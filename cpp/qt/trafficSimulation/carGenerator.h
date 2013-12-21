#ifndef CARGENERATOR_H
#define CARGENERATOR_H

#include <QGraphicsItem>
#include "misc.h"
#include "car.h"

class CarGenerator : public QGraphicsItem
{
	public:
		CarGenerator();
		CarGenerator( EPlace, qreal, qreal, QColor );
		
		QPainterPath shape() const;
		QRectF boundingRect() const;
		void paint( QPainter* painter, const QStyleOptionGraphicsItem* option,
				QWidget* widget );

	protected:
		void advance( int step );

	private:
		EPlace genPlace;
		QPointF genPoint;
		QColor genColor;
		int ticker;

};

#endif  // CARGENERATOR_H
