#ifndef CARFROM_H
#define CARFROM_H

#include "car.h"
#include <QGraphicsItem>
#include "misc.h"

/*---------------------------------------------------------------------------*/
/*                                  CarBSN                                   */
/*---------------------------------------------------------------------------*/
class CarBSN : public Car
{
	public:
		CarBSN( qreal speed );

	protected:
		void advance( int step );
};

/*---------------------------------------------------------------------------*/
/*                                  CarBSS                                   */
/*---------------------------------------------------------------------------*/
class CarBSS : public Car
{
	public:
		CarBSS( qreal speed );

	protected:
		void advance( int step );
};

/*---------------------------------------------------------------------------*/
/*                                  CarTBN                                   */
/*---------------------------------------------------------------------------*/
class CarTBN : public Car
{
	public:
		CarTBN( qreal speed );

	protected:
		void advance( int step );
};

/*---------------------------------------------------------------------------*/
/*                                  CarTBS                                   */
/*---------------------------------------------------------------------------*/
class CarTBS : public Car
{
	public:
		CarTBS( qreal speed );

	protected:
		void advance( int step );
};

/*---------------------------------------------------------------------------*/
/*                                  CarRHW                                   */
/*---------------------------------------------------------------------------*/
class CarRHW : public Car
{
	public:
		CarRHW( qreal speed );

	protected:
		void advance( int step );
};

/*---------------------------------------------------------------------------*/
/*                                  CarRHE                                   */
/*---------------------------------------------------------------------------*/
class CarRHE : public Car
{
	public:
		CarRHE( qreal speed );

	protected:
		void advance( int step );
};

#endif // CARFROM_H
