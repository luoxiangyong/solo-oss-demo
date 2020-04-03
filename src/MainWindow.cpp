#include "MainWindow.h"
#include <QtWidgets/QAction>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QApplication>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QPushButton>
#include <QtCore/QFile>
#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebFrame>

#include "config.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
	qDebug() << ">> " << int((QT_VERSION & 0xFF0000) >> 16) << "." 
					  << int((QT_VERSION & 0x00FF00) >> 8 )<< "."
					  << int((QT_VERSION & 0x0000FF)) ;
	

	setupMainUI();
	setupStyle();
    /*1、菜单、工具条的状态栏提示*/

	//创建QAction对象
	openAction = new QAction("&Open",this);
	//设置快捷键
	openAction->setShortcut(QKeySequence::Open);
	//状态栏提示
	openAction->setStatusTip("Open a file");
	//加载图标
	openAction->setIcon(QIcon(":/QtStudy9/Resources/qt.PNG"));
 
	//connect(openAction,SIGNAL(triggered()),this,SLOT(open()));
 
	//把Action添加到菜单和工具条
	
	QMenu* mfile = menuBar()->addMenu("&File");
	mfile->addAction(openAction);
	//QToolBar* tfile = addToolBar("&File");
	//tfile->addAction(openAction);
 
	/*2、状态栏的临时信息、一般信息、永久信息的显示*/
 
	msgLable = new QLabel;
	msgLable->setMinimumSize(150,20/*msgLable->sizeHint()*/);
	msgLable->setAlignment(Qt::AlignHCenter);
	statusBar()->addWidget(msgLable);
	//statusBar()->showMessage("lin shi xin xi ",3000);//3s后关闭

	QStatusBar* bar = statusBar(); //获取状态栏
	QLabel* first_statusLabel = new QLabel; //新建标签
	first_statusLabel->setMinimumSize(150,20); //设置标签最小尺寸
	//first_statusLabel->setFrameShape(QFrame::WinPanel); //设置标签形状
	//first_statusLabel->setFrameShadow(QFrame::Sunken); //设置标签阴影
 
	QLabel* second_statusLabel = new QLabel;
	//second_statusLabel->setMinimumSize(150,20);
	//second_statusLabel->setFrameShape(QFrame::WinPanel);
	//second_statusLabel->setFrameShadow(QFrame::Sunken);
 
	QLabel* third_statusLabel = new QLabel;
	QLabel* four_statusLabel = new QLabel;
 
	//显示一般信息栏
	bar->addWidget(first_statusLabel);
	
	//显示永久信息栏
	bar->addPermanentWidget(second_statusLabel);
	bar->addPermanentWidget(third_statusLabel);
	//bar->insertPermanentWidget(3, four_statusLabel);
	bar->addPermanentWidget(four_statusLabel);
 
	//first_statusLabel->setText(tr("GPS")); //初始化内容
	second_statusLabel->setText(tr("CAMERA"));
	third_statusLabel->setText("GPS");
	four_statusLabel->setText(THE_BUILD_HOST);
 
	//最后显示临时信息
	statusBar()->showMessage("系统就绪 ",3000);//3s后关闭
	statusBar()->setStyleSheet(QString("QStatusBar::item{border:0px}"));
}

void MainWindow::setupMainUI() 
{
	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	QTabWidget* mainTabPanel = new QTabWidget();
	//mainPanel->setContentsMargins(0,0,0,0);
	mainTabPanel->setLayout(mainLayout);
	this->setCentralWidget(mainTabPanel);

	//mainTabPanel->setTabPosition(Qt::Or)

	QWidget* webViewPanel = new QWidget;
	mainTabPanel->addTab(webViewPanel, "地图显示");
	QVBoxLayout* webViewPanelLayout = new QVBoxLayout();
	webViewPanelLayout->setContentsMargins(0,0,0,0);
	webViewPanel->setLayout(webViewPanelLayout);

	NavigationView* naviView = new NavigationView();
	mainTabPanel->addTab(naviView, "导航状态");


	/////
	QString mapHtmlUrl = QString("file:///%1/../share/%2/html/baidu-map.html")
						.arg(QApplication::applicationDirPath())
						.arg(PACKAGE_NAME);
	//QMessageBox::information(NULL, "Diagnostic", mapHtmlUrl, 
    //                     QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	qDebug() << mapHtmlUrl;

//#endif
#ifdef QT5_HAVE_WEBENGINE
	mapView = new QWebEngineView();
	QWebEnginePage *page = new QWebEnginePage(this);  // 定义一个page作为页面管理
	QWebChannel *channel = new QWebChannel(this);     // 定义一个channel作为和JS或HTML交互
	page->load(mapHtmlUrl);							// page上加载html路径
	page->setWebChannel(channel);					// 把channel配置到page上，让channel作为其信使
	ui->webEngine->setPage(page);					// 建立page和UI上的webEngine的联系

#else
	mapView = new WebView();

	//webview
	connect(mapView->page()->mainFrame(), SIGNAL(javaScriptWindowObjectCleared()),
					this, SLOT(populateJavaScriptWindowObject()));
	
	mapView->load(QUrl(mapHtmlUrl));
	
#endif
	
	webViewPanelLayout->addWidget(mapView);

	QWidget* webViewControlPanel = new QWidget;
	webViewControlPanel->setFixedHeight(25);
	//webViewControlPanel->setMinimumHeight(50);
	QHBoxLayout* webViewControlPanelLayout = new QHBoxLayout();
	
	webViewControlPanelLayout->setContentsMargins(0,0,0,0);
	//webViewControlPanelLayout->setSizeConstraint(QLayout::)
	webViewControlPanel->setLayout(webViewControlPanelLayout);
	webViewControlPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
	//QSpacerItem* horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    //webViewControlPanelLayout->addItem(horizontalSpacer);
	webViewControlPanelLayout->addStretch();
	QPushButton* updateStyle = new QPushButton("更新样式",this);
	QLabel* logLabel = new QLabel("经度");
	longEdit = new QLineEdit();
	QLabel* latLabel = new QLabel("纬度");
	latEdit = new QLineEdit();
	QLabel* levelLabel = new QLabel("层数");
	levelEdit = new QLineEdit();
	QPushButton* changeLoationButton = new QPushButton("去这里",this);

	webViewControlPanelLayout->addWidget(updateStyle);
	webViewControlPanelLayout->addWidget(logLabel);
	webViewControlPanelLayout->addWidget(longEdit);
	webViewControlPanelLayout->addWidget(latLabel);
	webViewControlPanelLayout->addWidget(latEdit);
	webViewControlPanelLayout->addWidget(levelLabel);
	webViewControlPanelLayout->addWidget(levelEdit);
	webViewControlPanelLayout->addWidget(changeLoationButton);
	
	connect(changeLoationButton, SIGNAL(clicked()), this, SLOT(changeCurrentLocation()));
	connect(updateStyle, SIGNAL(clicked()), this, SLOT(setupStyle()));

	webViewPanelLayout->addWidget(webViewControlPanel);
}

void MainWindow::populateJavaScriptWindowObject()
{
	mapView->page()->mainFrame()->addToJavaScriptWindowObject("mainWindow", this);
}

void MainWindow::changeCurrentLocation()
{
	//qDebug() << QString("经纬度：(%1,%2)").arg(longEdit->text()).arg(latEdit->text()).toStdString().c_str();
	QString js = QString("changeCurrentLocation(%1,%2,%3)").arg(longEdit->text().toFloat())
														   .arg(latEdit->text().toFloat())
														   .arg(levelEdit->text().toUInt());
	qDebug() << js;       
#ifdef QT5_HAVE_WEBENGINE	
	mapView->page()->runJavaScript(js);
#else
    mapView->page()->mainFrame()->evaluateJavaScript(js);
#endif
}

void MainWindow::mapClicked(QString longtitude, QString latitude, QString level)
{
    longEdit->setText(longtitude);
    latEdit->setText(latitude);
	levelEdit->setText(level);
}

MainWindow::~MainWindow()
{

}

void MainWindow::setupStyle()
{
	QString qssFilePath = QString("%1/../share/%2/theme/default.qss")
						.arg(QApplication::applicationDirPath())
						.arg(PACKAGE_NAME);
	QFile qssFile(qssFilePath);
	qssFile.open(QIODevice::ReadOnly | QIODevice::Text);
	QString qssString = QString(qssFile.readAll());
	qssFile.close();
	
	this->setStyleSheet(qssString);

	//qDebug() << qssString;
}