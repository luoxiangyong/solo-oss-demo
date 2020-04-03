#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "solo_basic.h"
#include <QtCore/QDebug>
#include <libintl.h>
#include "MainWindow.h"
#include "config.h"

int main(int argn, char** argv)
{
	QApplication app(argn,argv);
	QString moPath = QString("%1/../share/%2/locale")
						.arg(QApplication::applicationDirPath())
						.arg(PACKAGE_NAME);
	//bindtextdomain("solo-oss-demo", "/usr/share/locale");
	bindtextdomain(PACKAGE_NAME, moPath.toStdString().c_str());
  	textdomain(PACKAGE_NAME);

	qDebug() << moPath;

	MainWindow mainWindow;

	mainWindow.setWindowTitle(_("A Simple Photogrammetric Aerial Navigation Viewer"));
	mainWindow.resize(800,600);

	mainWindow.showMaximized();
	
	return app.exec();
}

