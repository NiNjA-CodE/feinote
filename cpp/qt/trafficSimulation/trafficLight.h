#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <QGraphicsItem>

class TrafficLight : public QGraphicItem
{
	public:
		TrafficLight();

	protected:
		advance();

	private:
		qreal timeOffset;
		QColor north;
		QColor south;
		QColor east;
		QColor west;

}

