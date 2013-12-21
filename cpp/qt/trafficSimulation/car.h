#ifndef CAR_H
#define CAR_H

#include <QGraphicsItem>
#include "misc.h"

class Car: public QGraphicsItem
{
	public:
		Car();
		Car( QPointF, QColor, EPlace );

		QRectF boundingRect() const;
		void paint( QPainter *painter, const QStyleOptionGraphicsItem *option,
				QWidget *widget );

		QPainterPath shape() const;
		void setStartPos();


	protected:
		//  Implement destruct of cars at some situation
		void advance( int step );

	private:
		//  Generated place
		EPlace genPlace;
		EPlace dist;

		QColor genColor;
		QColor distColor;

		QPointF genPoint;
		QPointF distPoint;

		qreal angle;
		qreal speed;

		qreal ticker;

};

#endif // CAR_H
