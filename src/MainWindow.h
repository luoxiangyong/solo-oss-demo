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
#include <QtWebChannel/QWebChannel>
#include "NavigationView.h"
#include "WebView.h"

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

    WebView* mapView;
    QWebChannel* webChannel;
};

#endif // MAINWINDOW_H
