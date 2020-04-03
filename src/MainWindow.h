#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMenu>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtCore/QDebug>
#include <QtCore/QUrl>

#include "solo_ui_config.h"
#ifdef QT5_HAVE_WEBENGINE
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebChannel/QWebChannel>
#else
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebPage>
#include <QtWebKitWidgets/QWebFrame>
#endif

#include "NavigationView.h"

#ifdef QT5_HAVE_WEBENGINE
#include "WebEngineView.h"
#else
#include "WebView.h"
#endif

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupMainUI();

public slots:
    void changeCurrentLocation();
    void mapClicked(QString longtitude, QString latitude,QString level);
    void populateJavaScriptWindowObject();
    void setupStyle();

public:
    QAction* openAction;
    QLabel* msgLable;
    
    QLineEdit* longEdit;
	QLineEdit* latEdit;
    QLineEdit* levelEdit;

    
#ifdef QT5_HAVE_WEBENGINE
	WebEngineView* mapView;
    QWebChannel* webChannel;
#else
	WebView* mapView;
#endif
};

#endif // MAINWINDOW_H
