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
	//  Init genPlace
	/*
	int what = qrand() % 10;
	if( what == 0 ) {
		genPlace = eBSN;
		genColor = Qt::blue;
	}
	else if( what == 1 ){
		genPlace = eBSS;
		genColor = Qt::yellow;
	}
	else if( what == 2 ) {
		genPlace = eTBN;
		genColor = Qt::cyan;
	}
	else if(what == 3 ) {
		genPlace = eTBS;
		genColor = Qt::gray;
	}
	else if( what == 4 || what == 5 || what == 6 ) {
		genPlace = eRHW;
		genColor = Qt::black;
	}
	else {
		genPlace = eRHE;
		genColor = Qt::magenta;
	}

	//  Init distination
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace) % 5);

	genPlace = eBSN;
	genColor = Qt::blue;
	dist = eBSS;
	distColor = Qt::yellow;

	speed = 1;

	ticker = 70;
	*/
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
	painter->drawRect( -2.5, -5, 5, 10 );

	//  Car front window
	painter->setBrush( pointColor[dist] );
	painter->drawRect( -2, 0.5, 4, 4 );

}

/*---------------------------------------------------------------------------*/
/*                         virtual advance                                   */
/*---------------------------------------------------------------------------*/
/*
void Car::advance( int step )
{
	if(!step)
		return;

	if (ticker == 65) {
		//  Check traffic light
	}

	QPointF p1( -337.5, -87.5 );
	if ( this->mapToScene( 0, 0 ) == p1 ) {
		setRotation( 90 );
	}

	setPos( mapToParent( 0, 0.5 ));
	ticker--;
}
*/









