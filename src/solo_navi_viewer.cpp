#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtCore/QUrl>
#include "solo_basic.h"
#include "NavigationView.h"
#include <libintl.h>
#include "MainWindow.h"
#include "WebView.h"

int main(int argn, char** argv)
{
	bindtextdomain("solo-oss-demo", "/usr/share/locale");
  	textdomain("solo-oss-demo");

	QApplication app(argn,argv);

	MainWindow mainWindow;

	mainWindow.setWindowTitle(_("A Simple Photogrammetric Aerial Navigation Viewer"));
	mainWindow.resize(800,600);

	//mainWindow.setContentsMargins(0,0,0,0);

	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->setContentsMargins(0,0,0,0);
	QTabWidget* mainTabPanel = new QTabWidget();
	//mainPanel->setContentsMargins(0,0,0,0);
	mainTabPanel->setLayout(mainLayout);
	mainWindow.setCentralWidget(mainTabPanel);
	
	mainTabPanel->setStyleSheet("QTabWidget::pane{\
			border:none;\
		}\
		QTabWidget::tab-bar{\
			alignment:left;\
			background:black;\
		}\
		QTabBar::tab{\
			background:transparent;\
			color:black;\
			min-width:30ex;\
			min-height:10ex;\
		}\
		QTabBar::tab:hover{\
			background:rgb(255, 255, 255, 100);\
		}\
		QTabBar::tab:selected{\
			border-color: blue;\
			background:white;\
			color:green;\
		}");
	//mainTabPanel->setTabPosition(Qt::Or)

	NavigationView* naviView = new NavigationView();
	mainTabPanel->addTab(naviView, "导航状态");

	QWidget* webViewPanel = new QWidget;
	mainTabPanel->addTab(webViewPanel, "地图显示");
	QVBoxLayout* webViewPanelLayout = new QVBoxLayout();
	webViewPanelLayout->setContentsMargins(0,0,0,0);
	webViewPanel->setLayout(webViewPanelLayout);

	WebView* mapView = new WebView();
	mapView->load(QUrl("file:///C:/study/solo-oss-demo/src/html/baidu-map.html"));
	webViewPanelLayout->addWidget(mapView);

	QWidget* webViewControlPanel = new QWidget;
	webViewControlPanel->setMinimumHeight(50);
	QHBoxLayout* webViewControlPanelLayout = new QHBoxLayout();
	
	webViewControlPanelLayout->setContentsMargins(0,0,0,0);
	//webViewControlPanelLayout->setSizeConstraint(QLayout::)
	webViewControlPanel->setLayout(webViewControlPanelLayout);
	webViewControlPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
	QLabel* logLabel = new QLabel("经度");
	QLineEdit* longEdit = new QLineEdit();
	QLabel* latLabel = new QLabel("纬度");
	QLineEdit* latEdit = new QLineEdit();
	webViewControlPanelLayout->addWidget(logLabel);
	webViewControlPanelLayout->addWidget(longEdit);
	webViewControlPanelLayout->addWidget(latLabel);
	webViewControlPanelLayout->addWidget(latEdit);
	
	QSpacerItem* horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    webViewControlPanelLayout->addItem(horizontalSpacer);

	webViewPanelLayout->addWidget(webViewControlPanel);

	mainWindow.showMaximized();
	
	return app.exec();
}

