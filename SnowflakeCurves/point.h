#ifndef POINT_H
#define POINT_H

class Point
{
private:
    float mX, mY;

public:
    Point (void) { mX = 0; mY = 0; };
    Point (float a, float b) { mX = a; mY = b; };
    void setPoint (float a, float b) { mX = a; mY = b; };
    float getX(void) { return mX; };
    void setX(float a) { mX = a; };
    float getY(void) { return mY; };
    void setY(float b) { mY = b; };
    void rotate(float);
};




class IntPoint
{
private:
    int mX, mY;

public:
    IntPoint (void) { mX = 0; mY = 0; };
    IntPoint (int a, int b) { mX = a; mY = b; };
    void setPoint (int a, int b) { mX = a; mY = b; };
    int getX(void) { return mX; };
    int getY(void) { return mY; };
};


#endif
