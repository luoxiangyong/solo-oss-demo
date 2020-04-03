#ifndef WebEngineView_H
#define WebEngineView_H

#include <QtWebEngineWidgets/QWebEngineView>

class  WebEngineView : public QWebEngineView
{
	Q_OBJECT
public:
	WebEngineView(QWidget* parent = NULL);
	~WebEngineView();

	void paintEvent(QPaintEvent* event);

	void keyPressEvent(QKeyEvent *event);
};

#endif // WebEngineView_H
