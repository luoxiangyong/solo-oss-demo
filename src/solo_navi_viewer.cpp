#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
//#include <QtWidgets/QPanek
#include <QtWidgets/QVBoxLayout>

#include "solo_basic.h"
#include "NavigationView.h"


int main(int argn, char** argv)
{
	bindtextdomain("solo-oss-demo", "/usr/share/locale");
  	textdomain("solo-oss-demo");

	QApplication app(argn,argv);

	QMainWindow mainWindow;

	mainWindow.setWindowTitle(_("A Simple Photogrammetric Aerial Navigation Viewer"));
	mainWindow.resize(800,600);

	QVBoxLayout* mainLayout = new QVBoxLayout();

	QWidget* mainPanel = new QWidget();
	mainPanel->setLayout(mainLayout);
	mainWindow.setCentralWidget(mainPanel);
	
	NavigationView* myView = new NavigationView();
	mainLayout->addWidget(myView);

	mainWindow.show();

	return app.exec();

}

