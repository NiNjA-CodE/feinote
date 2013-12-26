#ifndef CARFROM_H
#define CARFROM_H

#include "car.h"
#include <QGraphicsItem>
//#include "misc.h"

/*---------------------------------------------------------------------------*/
/*                                  CarBSN                                   */
/*---------------------------------------------------------------------------*/
class CarBSN : public Car
{
	public:
		CarBSN( qreal speed );
		virtual ~CarBSN();

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
		virtual ~CarBSS();

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
		virtual ~CarTBN();

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
		virtual ~CarTBS();

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
		virtual ~CarRHW();

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
		virtual ~CarRHE();

	protected:
		void advance( int step );
};

#endif // CARFROM_H
