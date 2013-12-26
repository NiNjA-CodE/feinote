#ifndef CAR_H
#define CAR_H

#include <QGraphicsItem>
#include "misc.h"
//#include "trafficLight.h"
//#include "userDefines.h"

class Car: public QGraphicsItem
{
	public:
		Car();
		virtual ~Car();
		//Car( QPointF, QColor, EPlace );
		Car( EPlace, EPlace, qreal );

		QRectF boundingRect() const;
		void paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
				QWidget *widget );

		QPainterPath shape() const;
		void setStartPos();

		bool ableToForward( TrafficLight*, ELightDirct ) const;
		void checkLightForward( ) ;


	protected:
		//virtual void advance( int step );

	public:
		EPlace genPlace;
		EPlace dist;
		qreal speed;
		volatile bool forward;

		//qreal ticker;

};

#endif // CAR_H
