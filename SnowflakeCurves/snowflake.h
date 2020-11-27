#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H
#include "flake.h"
#include "maindialog.h"
#include <array>
#include <vector>
#include "matrix.h"
#include "graphics.h"

class Snowflake
{

private:
    QWidget *mScreen;
    Point mImageSize;
    float mCenterX;
    float mCenterY;
    QPainter *mPainter;
    int max_level;
    Matrix *mObject;
    Matrix m_move_matrix;
    std::array<std::array<float,3>,3> *mInitiator;
    std::vector<std::array<std::array<float,3>,3>> mInitiators;
    std::vector<std::array<std::array<float,3>,3>> mGenerators;

public:
    Snowflake(Point, QPainter &, Flake &flakeData);
    std::vector<Point> polyGenerator(Flake &flakeData);
    void initInitiator(int);
    void initGenerator(std::vector<Point> points);
    void process(void);
    void generate(Matrix pmatrix, int level);
    void drawIterator(void);
    void drawGenerator(void);
    void drawLineList(std::vector<std::array<std::array<float,3>,3>> &lines);
};

#endif
