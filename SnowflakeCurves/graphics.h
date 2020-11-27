#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "point.h"
#include "matrix.h"
#include <QPainter>
#include <QWidget>

class Line : public Matrix
{
private:
  float mCenterX;
  float mCenterY;
  Point mImageSize;
  QPainter * mPainter;

public:
  Line(Point, Point);
  Line(Point, QPainter &);

  Point getStart();
  Point getEnd();

  float length(void);
  void setPoints(Point start, Point end);
  void draw(void);

};

class Circle : public Matrix
{
private:
  float mCenterX;
  float mCenterY;
  Point mImageSize;
  QPainter * mPainter;

public:
  Circle(Point, Point);
  Circle(Point, QPainter &);

  Point getStart();
  Point getEnd();

  float length(void);
  void setPoints(Point start, Point end);
  void draw(void);

};

#endif
