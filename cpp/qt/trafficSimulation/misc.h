#ifndef MISC_H
#define MISC_H


enum EPlace {
	eBSN = 0,  //  Baisha North
	eBSS,	   //  Baisha South
	eTBN,      //  Taibai North
	eTBS,      //  Taibai South
	eRHW,      //  Erhuan West
	eRHE       //  Erhuan East
};
	
static const QPointF startPoint[6] = {
	QPointF(-337.5, -150),		//  startPoint[eBSN]
	QPointF(-312.5, 150),		//  startPoint[eBSS]
	QPointF(312.5, -150),		//  startPoint[eTBN]
	QPointF(337.5, 150),		//  startPoint[eTBS]
	QPointF(-500, -62.5),		//  startPoint[eRHW]
	QPointF(500, -87.5)		//  startPoint[eRHE]
};

static const QPointF endPoint[6] = {
	QPointF(-312.5, -150),		//  endPoint[eBSN]
	QPointF(-337.5, 150),		//  endPoint[eBSS]
	QPointF(337.5, -150),		//  endPoint[eTBN]
	QPointF(312.5, 150),		//  endPoint[eTBS]
	QPointF(-500, -87.5),		//  endPoint[eRHW]
	QPointF(500, -62.5)		//  endPoint[eRHE]
};

//  Where to check traffic Light status.
static const QPointF lightCr1BSN = QPointF(-337.5, -100);
static const QPointF lightCr1BSS = QPointF(-312.5, -50);
static const QPointF lightCr1RHW = QPointF(-350, -62.5);
static const QPointF lightCr1RHE = QPointF(-300, -87.5);

static const QPointF lightCr2TBN = QPointF(-312.5, -100);
static const QPointF lightCr2TBS = QPointF(-337.5, -50);
static const QPointF lightCr2RHW = QPointF(300, -62.5);
static const QPointF lightCr2RHE = QPointF(350, -87.5);

//  Turnning points 
static const QPointF BSN2RHW = QPointF(-337.5, -87.5);
static const QPointF RHE2BSN = QPointF(-312.5, -87.5);
static const QPointF RHW2BSS = QPointF(-337.5, -62.5);
static const QPointF BSS2RHE = QPointF(-312.5, -62.5);

static const QPointF RHWDown = QPointF(-500, -87.5);
static const QPointF RHWUp = QPointF(-500, -62.5);
static const QPointF RHWRight = QPointF(500, -62.5);
static const QPointF RHWLeft = QPointF(500, -87.5);

static const QPointF TBN2RHW = QPointF(312.5, -87.5);
static const QPointF RHE2TBN = QPointF(337.5, -87.5);
static const QPointF RHW2TBS = QPointF(312.5, -62.5);
static const QPointF TBS2RHE = QPointF(337.5, -62.5);

//  Color tags of cars from different road point
static const QColor pointColor[6] = {
	Qt::blue,			//  pointColor[eBSN]
	Qt::yellow,			//  pointColor[eBSS]
	Qt::cyan,           //  pointColor[eTBN]
	Qt::gray,           //  pointColor[eTBS]
	Qt::black,          //  pointColor[eRHW]
	Qt::magenta         //  pointColor[eRHE]
};

#endif //  MISC_H
