#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QGraphicsItem>
#include "misc.h"


enum ELightDirct {
	eNS = 0,
	eWE
};

class TrafficLight : public QGraphicsItem
{
	public:
		//TrafficLight();
		//  param sec is real world second
		TrafficLight( int sec );
		QColor getLightStatus( ELightDirct );
		//void setStartPos();

		QRectF boundingRect() const;
		void paint( QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* Widget );
		QPainterPath shape() const;


	protected:
		 void advance( int step );

	private:
		int ticker;
		//QColor northSouth;
		//QColor westEast;

};

#endif  //  TRAFFICLIGHT_H

