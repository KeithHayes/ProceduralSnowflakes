#include "graphics.h"
#include "misc.h"
#include "point.h"

#include <QtMath>


Line::Line(Point start, Point end){
    // set matrix
    float a = end.getX() - start.getX();
    float b = end.getY() - start.getY();
    float length =  qSqrt(a*a+b*b);
    float angle = qAtan(b/a);
    setMval(IntPoint(0,0),length*qCos(angle));
    setMval(IntPoint(0,1),length*-qSin(angle));
    setMval(IntPoint(0,2),(start.getX() + end.getX())/2);
    setMval(IntPoint(1,0),length*qSin(angle));
    setMval(IntPoint(1,1),length*qCos(angle));
    setMval(IntPoint(1,2),(start.getY() + end.getY())/2);
    setMval(IntPoint(2,0),0);
    setMval(IntPoint(2,1),0);
    setMval(IntPoint(2,2),1);
}

Line::Line(Point imageSize, QPainter &painter) {
    mImageSize = imageSize;
    this->mPainter = &painter;
    this->setIdentity();
}

float Line::length(void) {
    float a = getEnd().getX()-getStart().getX();
    float b = getEnd().getY()-getStart().getY();
    return qSqrt(a*a+b*b);
}

void Line::setPoints(Point start, Point end) {
    float a = end.getX() - start.getX();
    float b = end.getY() - start.getY();
    float length =  qSqrt(a*a+b*b);
    float angle = qAtan(b/a);
    setMval(IntPoint(0,0),length*qCos(angle));
    setMval(IntPoint(0,1),length*-qSin(angle));
    setMval(IntPoint(0,2),(start.getX() + end.getX())/2);
    setMval(IntPoint(1,0),length*qSin(angle));
    setMval(IntPoint(1,1),length*qCos(angle));
    setMval(IntPoint(1,2),(start.getY() + end.getY())/2);
}

Point Line::getStart(void){
    return this->multiply(Point(-0.5,0));
}

Point Line::getEnd(void){
    return this->multiply(Point(0.5,0));
}

void Line::draw() {
    float xResult = -0.5*getCoeff(IntPoint(0,0))+getCoeff(IntPoint(0,2));
    float yResult = -0.5*getCoeff(IntPoint(1,0))+getCoeff(IntPoint(1,2));
    Point start = Point(xResult, yResult);
    xResult = 0.5*getCoeff(IntPoint(0,0))+getCoeff(IntPoint(0,2));
    yResult = 0.5*getCoeff(IntPoint(1,0))+getCoeff(IntPoint(1,2));
    Point end = Point(xResult, yResult);
    int centerX = mImageSize.getX()/2;
    int centerY = mImageSize.getY()/2;
    int scale = MINSIZE(centerX,centerY);
    float x1 = scale * start.getX() + centerX;
    float x2 = scale * end.getX() + centerX;
    float y1 = -scale * start.getY() + centerY;
    float y2 = -scale * end.getY() + centerY;
    this->mPainter->drawLine(x1,y1,x2,y2);
}




Circle::Circle(Point start, Point end){
    // set matrix
    float a = end.getX() - start.getX();
    float b = end.getY() - start.getY();
    float length =  qSqrt(a*a+b*b);
    float angle = qAtan(b/a);
    setMval(IntPoint(0,0),length*qCos(angle));
    setMval(IntPoint(0,1),length*-qSin(angle));
    setMval(IntPoint(0,2),(start.getX() + end.getX())/2);
    setMval(IntPoint(1,0),length*qSin(angle));
    setMval(IntPoint(1,1),length*qCos(angle));
    setMval(IntPoint(1,2),(start.getY() + end.getY())/2);
    setMval(IntPoint(2,0),0);
    setMval(IntPoint(2,1),0);
    setMval(IntPoint(2,2),1);
}

Circle::Circle(Point imageSize, QPainter &painter) {
    mImageSize = imageSize;
    this->mPainter = &painter;
    this->setIdentity();
}

float Circle::length(void) {
    float a = getEnd().getX()-getStart().getX();
    float b = getEnd().getY()-getStart().getY();
    return qSqrt(a*a+b*b);
}

void Circle::setPoints(Point start, Point end) {
    float a = end.getX() - start.getX();
    float b = end.getY() - start.getY();
    float length =  qSqrt(a*a+b*b);
    float angle = qAtan(b/a);
    setMval(IntPoint(0,0),length*qCos(angle));
    setMval(IntPoint(0,1),length*-qSin(angle));
    setMval(IntPoint(0,2),(start.getX() + end.getX())/2);
    setMval(IntPoint(1,0),length*qSin(angle));
    setMval(IntPoint(1,1),length*qCos(angle));
    setMval(IntPoint(1,2),(start.getY() + end.getY())/2);
}

Point Circle::getStart(void){
    return this->multiply(Point(-0.5,0));
}

Point Circle::getEnd(void){
    return this->multiply(Point(0.5,0));
}

void Circle::draw() {
    float xResult = -0.5*getCoeff(IntPoint(0,0))+getCoeff(IntPoint(0,2));
    float yResult = -0.5*getCoeff(IntPoint(1,0))+getCoeff(IntPoint(1,2));
    Point start = Point(xResult, yResult);
    xResult = 0.5*getCoeff(IntPoint(0,0))+getCoeff(IntPoint(0,2));
    yResult = 0.5*getCoeff(IntPoint(1,0))+getCoeff(IntPoint(1,2));
    Point end = Point(xResult, yResult);
    int centerX = mImageSize.getX()/2;
    int centerY = mImageSize.getY()/2;
    int scale = MINSIZE(centerX,centerY);
    float x1 = scale * start.getX() + centerX;
    float x2 = scale * end.getX() + centerX;
    float y1 = -scale * start.getY() + centerY;
    float y2 = -scale * end.getY() + centerY;
    float length = qSqrt(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
    float xpos = x1-length/2;
    float ypos = y1-length/2;
    this->mPainter->drawEllipse(QRectF(xpos,ypos,length,length));
}
