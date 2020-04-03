#include "WebEngineView.h"
#include <QtGui/QPalette>
#include <QtGui/QBrush>

WebEngineView::WebEngineView(QWidget* parent ) : QWebEngineView(parent) 
{
	this->setAutoFillBackground(true);
	QPalette palette(this->palette());
	//palette.setColor(QPalette::Background, QColor(108,106,90));
	palette.setColor(QPalette::Background, QColor(0,0,0));
	this->setPalette(palette);

	//currentOrientation = 190;

	setFocusPolicy(Qt::StrongFocus);
}

WebEngineView::~WebEngineView() 
{

}

void WebEngineView::paintEvent(QPaintEvent* event) 
{
    QWebEngineView::paintEvent(event); 
	 
	QPainter painter(this);  
	painter.setRenderHint(QPainter::Antialiasing);  
	painter.setRenderHint(QPainter::SmoothPixmapTransform);  
	painter.save();  

	QPen pen(QColor(0,0,0),1,Qt::DotLine);
	painter.setPen(pen);
	int x_interval = 50;
	int y_interval = 50;
	int x_margin = 20;
	int y_margin = 20;
	for(int i = 1; i < 10; i++){
		// draw x 
		painter.drawLine(x_margin, y_margin + i * y_interval, this->width() - x_margin, y_margin + i * y_interval);
		
		// draw y
		painter.drawLine(x_margin + i * x_interval, y_margin, x_margin + i * x_interval, this->height() - y_margin);
	}
	

	// header
	painter.setPen(Qt::NoPen);
	/* QBrush headerBrush(QColor(0,0,50,255));
	painter.setBrush(headerBrush);
	painter.drawRect(0,0, this->width(),50);
	painter.drawEllipse(50,-16,80,80); */

	// 临时状态
	int topMargin = 80;
	int leftMargin = this->width() - 350;
	QBrush msg1Brush(QColor(0,0,255,250));
	painter.setBrush(msg1Brush);
	painter.drawRect(leftMargin,topMargin,50,50);
	QBrush msg2Brush(QColor(255,255,255,250));
	painter.setBrush(msg2Brush);
	painter.drawRect(leftMargin + 55 ,topMargin,200,50);

	// 方向
	QBrush orientationBrush(QColor(50,50,50,250));
	painter.setBrush(orientationBrush);
	painter.drawEllipse(width() - 60 - 5, topMargin - 5, 60, 60);
	painter.setBrush(Qt::NoBrush);
	painter.setPen(QColor(21,38,56,255));
	painter.drawEllipse(width() - 60 , topMargin , 50, 50);
	
	////////////////////////////////////////////////////////////////////////////
	// 实时状态
	/* painter.setPen(Qt::NoPen);
	QBrush bottomBrush(QColor(21,38,56,255));
	painter.setBrush(bottomBrush);
	painter.drawRect(0, height() - 300 ,500, 300);

	int baseX = 170, baseY = height() - 100;

	painter.setBrush(QBrush(QColor(110,110,110))); */

	painter.restore(); 
}

void WebEngineView::keyPressEvent(QKeyEvent *event)
{
    QWebEngineView::keyPressEvent(event); 
}
