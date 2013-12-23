#include "car.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>


/*---------------------------------------------------------------------------*/
/*                                Constructor                                */
/*---------------------------------------------------------------------------*/
Car::Car() : speed(0.1), genPlace(eBSN), dist(eBSS)
{
	setRotation( 0 );
	setStartPos();

}

Car::Car( EPlace gen, EPlace dis, qreal fast ) :
	genPlace(gen), dist(dis), speed(fast)
{
	setStartPos();

}
	
/*---------------------------------------------------------------------------*/
/*                                setStartPos                                */
/*---------------------------------------------------------------------------*/
void Car::setStartPos()
{
	//setPos( -337.5, -150 );
	setPos( startPoint[genPlace] );
	//setPos( -337.5, -87.5 );
}

/*---------------------------------------------------------------------------*/
/*                                 shape                                     */
/*---------------------------------------------------------------------------*/
QPainterPath Car::shape() const
{
	QPainterPath path;
	path.addRect( -2.5, -5, 5, 10 );
	return path;
}

/*---------------------------------------------------------------------------*/
/*                                boundingRect                               */
/*---------------------------------------------------------------------------*/
QRectF Car::boundingRect() const
{
	qreal adjust = 0.5;
	return QRectF( -2.5, -5 - adjust,
			5, 13 + adjust);
}


/*---------------------------------------------------------------------------*/
/*                                 paint                                     */
/*---------------------------------------------------------------------------*/
void Car::paint( QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	//  Car body
	painter->setBrush( pointColor[genPlace] );
	painter->drawRect( -3.5, -6, 7, 12 );

	//  Car front window
	painter->setBrush( pointColor[dist] );
	painter->drawRect( -3, 0.5, 6, 5 );

}

