#ifndef MATRIX_H
#define MATRIX_H

#include "point.h"
#include <array>

class Matrix
{

private:
    std::array<std::array<float,3>,3> mMatrix;

public:
    Matrix(void);
    void setMval(IntPoint p, float value) { mMatrix[p.getX()][p.getY()] = value; }
    float getCoeff(IntPoint p) { return mMatrix[p.getX()][p.getY()]; }
    std::array<std::array<float,3>,3> getMatrix(void) {return mMatrix;};
    void setMatrix(std::array<std::array<float,3>,3> m){ mMatrix = m; };
    Matrix& setIdentity(void);
    float multiSize(void);
    Point multiply(Point point);
    Matrix multiply(const Matrix& m) const;
    void rotateCW(float);
    void rotateCCW(float);
    void place(float,float);
    void move(float,float);
    void scale(float);
    Matrix operator*=(const Matrix& m);
    virtual void draw(void){};

};

#endif
