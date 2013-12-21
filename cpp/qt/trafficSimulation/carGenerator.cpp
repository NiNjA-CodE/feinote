#include "carGenerator.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>

/*---------------------------------------------------------------------------*/
/*                               constructor                                 */
/*---------------------------------------------------------------------------*/
CarGenerator::CarGenerator() 
{
	ticker = 59;
}

CarGenerator::CarGenerator( EPlace place, qreal x, qreal y, QColor color) : 
	genPlace(place), genPoint(QPointF(x,y)), genColor(color), ticker(59)
{

}

/*---------------------------------------------------------------------------*/
/*                                boundingRect                               */
/*---------------------------------------------------------------------------*/
QRectF CarGenerator::boundingRect() const
{
	return QRectF( 0, 0, 0, 0 );
}

/*---------------------------------------------------------------------------*/
/*                                paint                                      */
/*---------------------------------------------------------------------------*/
void CarGenerator::paint( QPainter*, const QStyleOptionGraphicsItem*, QWidget* )
{
}

/*---------------------------------------------------------------------------*/
/*                                shape                                      */
/*---------------------------------------------------------------------------*/
QPainterPath CarGenerator::shape() const
{
	QPainterPath path;
	path.addRect( 0, 0, 0, 0 );
	return path;
}

/*---------------------------------------------------------------------------*/
/*                                advance                                    */
/*---------------------------------------------------------------------------*/
void CarGenerator::advance( int step )
{
	if(!step)
		return;

	if(ticker == 59) 
	{
		Car* pgotcar = new Car( genPoint, genColor, genPlace );
		this->scene()->addItem( pgotcar );
		ticker = 0;
	}
	else
	{
		++ticker;
	}
}


