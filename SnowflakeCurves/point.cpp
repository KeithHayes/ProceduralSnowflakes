#include "point.h"
#include <QtMath>

void Point::rotate(float angle) {
    float pointX = getX()*qCos(angle)+getY()*qSin(angle);
    float pointY = -getX()*qSin(angle)+getY()*qCos(angle);
    setX(pointX);
    setY(pointY);
}
