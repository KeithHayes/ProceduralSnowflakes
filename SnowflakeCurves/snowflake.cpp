#include "snowflake.h"
#include "point.h"
#include "graphics.h"
#include "misc.h"

#include <QtMath>
#include <string>
#include <regex>
#include <sstream>

Snowflake::Snowflake(Point imageSize, QPainter &painter, Flake &flakeData) {
    mPainter = &painter;
    mImageSize = imageSize;
    if (!flakeData.getCircle()) { mObject = new Line(imageSize,painter); }
    else                        { mObject = new Circle(imageSize,painter); }
    float xOffset = flakeData.getXoffset()/flakeData.getScale();
    float yOffset = flakeData.getYoffset()/flakeData.getScale();
    mObject->move(xOffset,yOffset);
    mObject->scale(flakeData.getScale());
    mObject->rotateCW(flakeData.getPitch());
    max_level  = flakeData.getLevels();
    initInitiator(flakeData.getSides());
    std::vector<Point> genpoints;
    switch(flakeData.getType()) {
        case ShapeType::koch :
            genpoints = KOCH;
            break;
        case ShapeType::square :
            genpoints = SQUARE;
            break;
        case ShapeType::peano :
            genpoints = PEANO;
            break;
        case ShapeType::poly :
            genpoints = polyGenerator(flakeData);
            break;
        default :
            genpoints = PEANO;
            ;
    }
    initGenerator(genpoints);
    std::string str = flakeData.getColor();
    int r = std::stoi (str.substr(1,2),nullptr,16);
    int g = std::stoi (str.substr(3,2),nullptr,16);
    int b = std::stoi (str.substr(5,2),nullptr,16);
    QColor penColor(r, g, b);
    painter.setPen(penColor);
}

std::vector<Point> Snowflake::polyGenerator(Flake &flakeData){
    try {
    float x;
    Point p;
    std::vector<Point> points;
    std::string flakestr = flakeData.getPolyText();
    std::stringstream str_strm;
    std::string temp;
    std::regex rx("([-]*[0-9]+[\\.]*[0-9]*)");
    std::sregex_iterator next(flakestr.begin(), flakestr.end(), rx);
    std::sregex_iterator end;
    std::smatch match;
    for(std::sregex_iterator k =next;k!=end;++k) {
        match = *k;
        str_strm << match.str();
        temp = str_strm.str();
        x = atof(temp.c_str());
        str_strm.str("");
        ++k;
        match = *k;
        str_strm << match.str();
        temp = str_strm.str();
        p = Point(x,atof(temp.c_str()));
        str_strm.str("");
        points.push_back(p);
    }
    return points;
    }
    catch (int n) { }
    std::vector<Point> points;
    return points;
}

void Snowflake::initInitiator(int n) {
    Line *line;
    float angle = TWO_PI/n;
    line = new Line(Point(-0.5, 0),Point(0.5, 0));
    float l = qSin(angle/2);
    line->scale(l);
    line->rotateCW(angle/2);
    Point start = Point(0,0.5);
    Point end = Point(l*qCos(angle/2), 0.5-l*qSin(angle/2));
    Point center = Point((start.getX()+end.getX())/2, (start.getY()+end.getY())/2);
    line->place(center.getX(),center.getY());
    mInitiators.push_back(line->getMatrix());
    for(int i=0;i<n-1;i++){
        line->rotateCW(angle);
        center.rotate(angle);
        line->place(center.getX(),center.getY());
        mInitiators.push_back(line->getMatrix());
    }
}

void Snowflake::initGenerator(std::vector<Point> points) {
    Line *line;
    Point start = points.front();
    Point end = points.back();
    float length = qSqrt((end.getX()-start.getX())*(end.getX()-start.getX())+
    (end.getY()-start.getY())*(end.getY()-start.getY()));
    float angle = qAtan2((end.getY()-start.getY()),(end.getX()-start.getX()));
    for(int i=1;i<(int)points.size();i++){
        line = new Line(points[i-1],points[i]);
        line->scale(1/length);
        line->rotateCW(angle);
        line->move(-0.5,0);
        mGenerators.push_back(line->getMatrix());
    }
}

void Snowflake::drawIterator(void) { drawLineList(mInitiators); }
void Snowflake::drawGenerator(void) { drawLineList(mGenerators); }
void Snowflake::drawLineList(std::vector<std::array<std::array<float,3>,3>> &lines) {
    float xResult, yResult, x1, y1, x2 ,y2;
    Point start,end;
    for(int i=0;i<(int)lines.size();i++) {
        xResult = -0.5*lines[i][0][0]+lines[i][0][2];
        yResult = -0.5*lines[i][1][0]+lines[i][1][2];
        start = Point(xResult, yResult);
        xResult = 0.5*lines[i][0][0]+lines[i][0][2];
        yResult = 0.5*lines[i][1][0]+lines[i][1][2];
        end = Point(xResult, yResult);
        x1 = mCenterX * start.getX() + mCenterX;
        x2 = mCenterX * end.getX() + mCenterX;
        y1 = -mCenterY * start.getY() + mCenterY;
        y2 = -mCenterY * end.getY() + mCenterY;
        mPainter->drawLine(x1,y1,x2,y2);
    }
}

void Snowflake::process(void) {
    Matrix m_initiator_matrix;
    m_move_matrix.setMatrix(mObject->getMatrix());
    // loop the initiators
    for (int i=0;i<(int)mInitiators.size();i++) {
        m_initiator_matrix.setMatrix(mInitiators[i]);
        generate(m_move_matrix.multiply(m_initiator_matrix),0);
    }
}

void Snowflake::generate(Matrix pmatrix, int level) {
    Matrix m_gen_matrix;
    float lineSize = pmatrix.multiSize();
    if ((level >= max_level)||(lineSize<0.0025)) {
      // exit recursion
      mObject->setMatrix(pmatrix.getMatrix());
      mObject->draw();
      return;
    }
    level++;
    // loop the generators
    for(int i=0;i<(int)mGenerators.size();i++) {
        m_gen_matrix.setMatrix(mGenerators[i]);
        generate(pmatrix.multiply(m_gen_matrix),level);
    }
}
