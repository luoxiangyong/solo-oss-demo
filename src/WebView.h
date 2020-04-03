#ifndef WEB_VIEW_H
#define WEB_VIEW_H

#include <QtWebKitWidgets/QWebView>

class  WebView : public QWebView
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
