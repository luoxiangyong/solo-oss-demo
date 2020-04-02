#ifndef NavigationView_H
#define NavigationView_H

#include <QtWidgets/QWidget>
#include <QtGui/QPaintDevice>
#include <QtGui/QPaintEvent>
#include <QtGui/QPainter>
#include <QtGui/QKeyEvent>

class  NavigationView : public QWidget
{
	Q_OBJECT
public:
	NavigationView(QWidget* parent = NULL);
	~NavigationView();

	void paintEvent(QPaintEvent* event);

	void keyPressEvent(QKeyEvent *event);
	
	int currentOrientation;
};

#endif // NavigationView_H
