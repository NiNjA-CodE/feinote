#ifndef CAR_H
#define CAR_H

#include <QGraphicsItem>
#include "misc.h"

class Car: public QGraphicsItem
{
	public:
		Car();
		//Car( QPointF, QColor, EPlace );
		Car( EPlace, EPlace, qreal );

		QRectF boundingRect() const;
		void paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
				QWidget *widget );

		QPainterPath shape() const;
		void setStartPos();


	protected:
		//virtual void advance( int step );

	public:
		EPlace genPlace;
		EPlace dist;
		qreal speed;

		//qreal ticker;

};

#endif // CAR_H
