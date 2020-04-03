#include "NavigationView.h"
#include <QtGui/QPalette>
#include <QtGui/QBrush>

NavigationView::NavigationView(QWidget* parent ) : QWidget(parent) 
{
	this->setAutoFillBackground(true);
	QPalette palette(this->palette());
	//palette.setColor(QPalette::Background, QColor(108,106,90));
	palette.setColor(QPalette::Background, QColor(0,0,0));
	this->setPalette(palette);

	currentOrientation = 190;

	setFocusPolicy(Qt::StrongFocus);
}

NavigationView::~NavigationView() 
{

}

void NavigationView::paintEvent(QPaintEvent* event) 
{
	QWidget::paintEvent(event);  

	QPainter painter(this);  
	painter.setRenderHint(QPainter::Antialiasing);  
	painter.setRenderHint(QPainter::SmoothPixmapTransform);  
	painter.save();  

	QPen pen(QColor(0,255,0));
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
	QBrush headerBrush(QColor(21,38,56,255));
	painter.setBrush(headerBrush);
	painter.drawRect(0,0, this->width(),50);
	painter.drawEllipse(50,-20,80,80);

	// 临时状态
	int topMargin = 80;
	int leftMargin = this->width() - 350;
	QBrush msg1Brush(QColor(0,0,255,200));
	painter.setBrush(msg1Brush);
	painter.drawRect(leftMargin,topMargin,50,50);
	QBrush msg2Brush(QColor(255,255,255,200));
	painter.setBrush(msg2Brush);
	painter.drawRect(leftMargin + 55 ,topMargin,200,50);

	// 方向
	QBrush orientationBrush(QColor(50,50,50,200));
	painter.setBrush(orientationBrush);
	painter.drawEllipse(width() - 60 - 5, topMargin - 5, 60, 60);
	painter.setBrush(Qt::NoBrush);
	painter.setPen(QColor(21,38,56,255));
	painter.drawEllipse(width() - 60 , topMargin , 50, 50);
	
	////////////////////////////////////////////////////////////////////////////
	// 实时状态
	painter.setPen(Qt::NoPen);
	QBrush bottomBrush(QColor(21,38,56,200));
	painter.setBrush(bottomBrush);
	painter.drawRect(0, height() - 300 ,500, 300);

	int baseX = 170, baseY = height() - 100;

	painter.setBrush(QBrush(QColor(110,110,110)));

	// 圆
	int extCircleRaduis = 90, intCircleRaduis = 70;
	painter.drawEllipse(baseX - extCircleRaduis , baseY - extCircleRaduis , extCircleRaduis *2 , extCircleRaduis *2);
	painter.setBrush(QBrush(QColor(0,0,255)));
	painter.drawEllipse(baseX - intCircleRaduis , baseY - intCircleRaduis , intCircleRaduis *2 , intCircleRaduis *2);
	painter.setBrush(QBrush(QColor(21,38,56,255)));
	//int currentOrientation = 180;
	painter.drawPie(baseX - intCircleRaduis , baseY - intCircleRaduis , intCircleRaduis *2 , intCircleRaduis *2, 
						currentOrientation*16, 180*16);

	// 左标尺
	int rulerWidth = 30, rulerHeight = intCircleRaduis * 2;
	int leftRulerStartX = baseX - extCircleRaduis -10 - rulerWidth;
	int leftRulerStartY = baseY - intCircleRaduis;
	painter.setBrush(QBrush(QColor(21,38,30,255)));
	painter.drawRect(leftRulerStartX, leftRulerStartY, rulerWidth,rulerHeight);

	// 右标尺
	int rightRulerStartX = baseX + extCircleRaduis + 10;
	int rightRulerStartY = baseY - intCircleRaduis;
	painter.setBrush(QBrush(QColor(21,38,30,255)));
	painter.drawRect(rightRulerStartX, rightRulerStartY, rulerWidth,rulerHeight);


	painter.restore(); 
}

void NavigationView::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Right){
		currentOrientation -= 5;
	}else if(event->key() == Qt::Key_Left) {
		currentOrientation += 5;
	}else{
		QWidget::keyPressEvent(event);
	}

	if(currentOrientation > 180) currentOrientation = 180;
	if(currentOrientation < 0) currentOrientation = 0;

	update();
}

/*
void NavigationView::paintEvent(QPaintEvent* event) 
{
	QPainter painter(this);  
	painter.setRenderHint(QPainter::Antialiasing);  
	painter.setRenderHint(QPainter::SmoothPixmapTransform);  
	painter.save();  
	//线性渐变，渐变开始，和结束点  
	QLinearGradient linearGradient(10,10,100,100);  
	//创建了一个QLinearGradient对象实例，参数为起点和终点坐标，可作为颜色渐变的方向  
	//painter.setPen(Qt::NoPen);  
	linearGradient.setColorAt(0.0,Qt::green);  
	linearGradient.setColorAt(0.2,Qt::white);  
	linearGradient.setColorAt(0.4,Qt::blue);  
	linearGradient.setColorAt(0.6,Qt::red);  
	linearGradient.setColorAt(1.0,Qt::yellow);  
	painter.setBrush(QBrush(linearGradient));  
	painter.drawEllipse(10,10,100,100);  
	//前面为左边，后面两个参数为横轴和纵轴,上面的四行分别设置渐变的颜色和路径比例  

	//辐射渐变  
	QRadialGradient radialGradient(10+50 , 120+50, 50, 60, 170);  
	//创建了一个QRadialGradient对象实例，参数分别为中心坐标，半径长度和焦点坐标,如果需要对称那么中心坐标和焦点坐标要一致  
	radialGradient.setColorAt(0,Qt::green);  
	radialGradient.setColorAt(0.2,Qt::white);  
	radialGradient.setColorAt(0.4,Qt::blue);  
	radialGradient.setColorAt(0.6,Qt::red);  
	radialGradient.setColorAt(1.0,Qt::yellow);  
	painter.setBrush(QBrush(radialGradient));  
	painter.drawEllipse(10,120,100,100);//在相应的坐标画出来  

	//弧度渐变  
	QConicalGradient conicalGradient(10+50,  230 + 50,0);  
	//创建了一个QConicalGradient对象实例，参数分别为中心坐标和初始角度  
	conicalGradient.setColorAt(0,Qt::green);  
	conicalGradient.setColorAt(0.2,Qt::white);  
	conicalGradient.setColorAt(0.4,Qt::blue);  
	conicalGradient.setColorAt(0.6,Qt::red);  
	conicalGradient.setColorAt(0.8,Qt::yellow);  
	conicalGradient.setColorAt(1.0,Qt::green);  
	//设置渐变的颜色和路径比例  
	painter.setBrush(QBrush(conicalGradient));  
	painter.drawEllipse(10, 230, 100, 100);//在相应的坐标画出来  
	painter.restore();  

	painter.save();  
	QConicalGradient conicalGradient2(width()/2, height()/2, 90);  
	conicalGradient2.setColorAt(0, QColor(45, 204, 112));  
	conicalGradient2.setColorAt(1.0, QColor(51, 152, 219));  
	painter.setPen(QPen(QBrush(conicalGradient2), 30));  
	painter.drawEllipse(QRectF((width()/2 - 65), (height()/2 - 65), 130, 130));  
	painter.restore();  

	//QPainterPath画圆角矩形  
	painter.save();  
	const qreal radius = 26;  
	QPainterPath path;  
	QRectF rect = QRect(150, 10, 100, 100);  
	QLinearGradient myGradient(rect.topLeft(), rect.bottomRight());  
	myGradient.setColorAt(0.0,Qt::green);  
	myGradient.setColorAt(0.9,Qt::yellow);  
	path.moveTo(rect.topRight() - QPointF(radius, 0));  
	path.lineTo(rect.topLeft() + QPointF(radius, 0));  
	path.quadTo(rect.topLeft(), rect.topLeft() + QPointF(0, radius));  
	path.lineTo(rect.bottomLeft() + QPointF(0, -radius));  
	path.quadTo(rect.bottomLeft(), rect.bottomLeft() + QPointF(radius, 0));  
	path.lineTo(rect.bottomRight() - QPointF(radius, 0));  
	path.quadTo(rect.bottomRight(), rect.bottomRight() + QPointF(0, -radius));  
	path.lineTo(rect.topRight() + QPointF(0, radius));  
	path.quadTo(rect.topRight(), rect.topRight() + QPointF(-radius, -0));  
	painter.setBrush(myGradient);  
	painter.fillPath(path, QColor(Qt::green));  
	painter.drawPath(path);  
	painter.restore();  
	QWidget::paintEvent(event);  

}
*/