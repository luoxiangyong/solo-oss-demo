#include "MainWindow.h"
#include <QtWidgets/QAction>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include "config.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
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
	QToolBar* tfile = addToolBar("&File");
	tfile->addAction(openAction);
 
	/*2、状态栏的临时信息、一般信息、永久信息的显示*/
 
	msgLable = new QLabel;
	msgLable->setMinimumSize(150,20/*msgLable->sizeHint()*/);
	msgLable->setAlignment(Qt::AlignHCenter);
	statusBar()->addWidget(msgLable);
	//statusBar()->showMessage("lin shi xin xi ",3000);//3s后关闭

	QStatusBar* bar = statusBar(); //获取状态栏
	QLabel* first_statusLabel = new QLabel; //新建标签
	first_statusLabel->setMinimumSize(150,20); //设置标签最小尺寸
	first_statusLabel->setFrameShape(QFrame::WinPanel); //设置标签形状
	first_statusLabel->setFrameShadow(QFrame::Sunken); //设置标签阴影
 
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

MainWindow::~MainWindow()
{

}