#include "carFrom.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>


/*===========================================================================*/
/*                                Constructors                               */
/*===========================================================================*/

/*----- CarBSN --------------------------------------------------------------*/
CarBSN::CarBSN( qreal spd ) : Car( eBSN, eBSN, spd )
{
	//  Init distination
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
}

/*----- CarBSS --------------------------------------------------------------*/
CarBSS::CarBSS( qreal spd ) : Car( eBSS, eBSS, spd )
{
	//  Init distination
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
}

/*----- CarTBN --------------------------------------------------------------*/
CarTBN::CarTBN( qreal spd ) : Car( eTBN, eTBN, spd )
{
	//  Init distination
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
}

/*----- CarTBS --------------------------------------------------------------*/
CarTBS::CarTBS( qreal spd ) : Car( eTBS, eTBS, spd )
{
	//  Init distination
	//dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace) % 5);
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
}

/*----- CarRHW --------------------------------------------------------------*/
CarRHW::CarRHW( qreal spd ) : Car( eRHW, eRHW, spd )
{
	//  Init distination
	//dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace) % 5);
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
}

/*----- CarRHE --------------------------------------------------------------*/
CarRHE::CarRHE( qreal spd ) : Car( eRHE, eRHE, spd )
{
	//  Init distination
	dist = (enum EPlace) ((( qrand() % 5 ) + (int)genPlace +1) % 6);
	setStartPos();
}

/*===========================================================================*/
/*                                advance                                    */
/*===========================================================================*/

/*----- CarBSN --------------------------------------------------------------*/
void CarBSN::advance( int step )
{
	if(!step)
		return;


	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == BSN2RHW ) {
		setRotation( 90 );
	}
	else if ( curLocation == RHWDown ) {
		if ( dist != eRHW )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWRight ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist == eBSS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHWUp ) {
		if ( dist != eRHE )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWLeft ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHE2TBN ) {
		setRotation( 90 );
	}

	setPos( mapToParent( 0, 0.5 ));
}

/*----- CarBSS --------------------------------------------------------------*/
void CarBSS::advance( int step )
{
	if(!step)
		return;


	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == BSN2RHW ) {
		setRotation( 90 );
	}
	else if ( curLocation == RHWDown ) {
		if ( dist != eRHW )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWRight ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist == eBSS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHWUp ) {
		if ( dist != eRHE )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWLeft ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHE2TBN ) {
		setRotation( 90 );
	}

	setPos( mapToParent( 0, 0.5 ));
}
/*----- CarTBN --------------------------------------------------------------*/
void CarTBN::advance( int step )
{
	if(!step)
		return;


	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == BSN2RHW ) {
		setRotation( 90 );
	}
	else if ( curLocation == RHWDown ) {
		if ( dist != eRHW )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWRight ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist == eBSS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHWUp ) {
		if ( dist != eRHE )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWLeft ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHE2TBN ) {
		setRotation( 90 );
	}

	setPos( mapToParent( 0, 0.5 ));
}
/*----- CarTBS --------------------------------------------------------------*/
void CarTBS::advance( int step )
{
	if(!step)
		return;

	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == BSN2RHW ) {
		setRotation( 90 );
	}
	else if ( curLocation == RHWDown ) {
		if ( dist != eRHW )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWRight ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist == eBSS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHWUp ) {
		if ( dist != eRHE )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWLeft ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHE2TBN ) {
		setRotation( 90 );
	}


	setPos( mapToParent( 0, 0.5 ));
}
/*----- CarRHW --------------------------------------------------------------*/
void CarRHW::advance( int step )
{
	if(!step)
		return;


	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == BSN2RHW ) {
		setRotation( 90 );
	}
	else if ( curLocation == RHWDown ) {
		if ( dist != eRHW )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWRight ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist == eBSS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHWUp ) {
		if ( dist != eRHE )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWLeft ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHE2TBN ) {
		setRotation( 90 );
	}

	setPos( mapToParent( 0, 0.5 ));
}
/*----- CarRHE --------------------------------------------------------------*/
void CarRHE::advance( int step )
{
	if(!step)
		return;


	QPointF curLocation = this->mapToScene( 0, 0 );
	if ( curLocation == BSN2RHW ) {
		setRotation( 90 );
	}
	else if ( curLocation == RHWDown ) {
		if ( dist != eRHW )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWRight ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHW2BSS ) {
		if ( dist == eBSS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHW2TBS ) {
		if ( dist == eTBS )
		{
			setRotation( 90 );
		}
	}
	else if ( curLocation == RHWUp ) {
		if ( dist != eRHE )
		{ 
			setRotation( -90 );
		}
	}
	else if ( curLocation == RHWLeft ) {
		setRotation( -90 );
	}
	else if ( curLocation == RHE2TBN ) {
		setRotation( 90 );
	}

	setPos( mapToParent( 0, 0.5 ));
}
