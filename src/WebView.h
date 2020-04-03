#ifndef WEB_VIEW_H
#define WEB_VIEW_H

#include "solo_ui_config.h"
#ifdef QT5_HAVE_WEBENGINE
#include <QtWebKitWidgets/QWebEngineView>
#else
#include <QtWebKitWidgets/QWebView>
#endif

#ifdef QT5_HAVE_WEBENGINE
class  WebView : public QWebEngineView
#else
class  WebView : public QWebView
#endif
{
	Q_OBJECT
public:
	WebView(QWidget* parent = NULL);
	~WebView();

	void paintEvent(QPaintEvent* event);

	void keyPressEvent(QKeyEvent *event);
	
	//int currentOrientation;
};


#endif // WEB_VIEW_H