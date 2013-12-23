#include "trafficLight.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>


/*---------------------------------------------------------------------------*/
/*                                Constructor                                */
/*---------------------------------------------------------------------------*/
TrafficLight::TrafficLight( int tik ) : ticker( tik * freq ) 
{
}

/*---------------------------------------------------------------------------*/
/*                                 shape                                     */
/*---------------------------------------------------------------------------*/
//  Used for collision detection
QPainterPath TrafficLight::shape() const
{
	QPainterPath path;
	path.addRect( 0, 0, 0, 0 );
	return path;
}

/*---------------------------------------------------------------------------*/
/*                                boundingRect                               */
/*---------------------------------------------------------------------------*/
QRectF TrafficLight::boundingRect() const
{
	return QRectF( -26, -26 , 52, 52 );
}


/*---------------------------------------------------------------------------*/
/*                                 paint                                     */
/*---------------------------------------------------------------------------*/
void TrafficLight::paint( QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
	//  drow north and west direction traffic lights 
	QColor nscolor = getLightStatus( eNS );
	painter->setBrush( nscolor );
	painter->drawRect( -25, -25, 25, 5 );
	painter->drawRect( 0, 20, 25, 5 );

	//  drow west and east direction traffic lights 
	QColor wecolor = getLightStatus( eWE );
	painter->setBrush( wecolor );
	painter->drawRect( -25, 0, 5, 25 );
	painter->drawRect( 20, -25, 5, 25 );
}

/*---------------------------------------------------------------------------*/
/*                                 getLightStatus                            */
/*---------------------------------------------------------------------------*/
QColor TrafficLight::getLightStatus( ELightDirct dirc )
{
	if ( dirc == eNS ) 
	{
		if ( ticker >= 0 && ticker <= 119 * freq )
			return trafficLightRed;
		else 
			return trafficLightGreen;
	}
	else {
		if ( ticker >= 0 && ticker <= 119 * freq )
			return trafficLightGreen;
		else 
			return trafficLightRed;
	}
}


/*---------------------------------------------------------------------------*/
/*                                 advance                                   */
/*---------------------------------------------------------------------------*/
void TrafficLight::advance( int step )
{
	if ( !step )
		return;

	if ( ticker == 140 * freq - 1)
	{
		ticker = 0;
	}
	else 
	{
		++ticker;
	}
}

