#ifndef FLAKE_H
#define FLAKE_H
#include <string>
#include <QString>

enum class ShapeType { koch, peano, square, poly, circle, random };

class Flake
{
private:
    int mSides;
    int mLevels;
    float mScale;
    float mXmax;
    float mYmax;
    float mXoffset;
    float mYoffset;
    float mPitch;
    bool mCircle;
    ShapeType mtype;
    std::string mColor;
    std::string mPolyText;
    QString mFileName;

public:
    void setSides(int s) { mSides = s; };
    int getSides() { return mSides; };
    void setLevels(int l) { mLevels = l; };
    int getLevels() { return mLevels; };
    void setScale(float s) { mScale = s; };
    float getScale() { return mScale; };
    void setXmax(float x) { mXmax = x; };
    float getXmax() { return mXmax; };
    void setYmax(float y) { mYmax = y; };
    float getYmax() { return mYmax; };
    void setXoffset(float x) { mXoffset = x; };
    float getXoffset() { return mXoffset; };
    void setYoffset(float y) { mYoffset = y; };
    float getYoffset() { return mYoffset; };
    void setPitch(float p) { mPitch = p; };
    float getPitch() { return mPitch; };
    void setCircle(bool c) { mCircle = c; };
    bool getCircle() { return mCircle; };
    void setType(ShapeType t) { mtype = t; };
    ShapeType getType() { return mtype; };
    void setColor(std::string c) { mColor = c; };
    std::string getColor() { return mColor; };
    void setPolyText(std::string p) { mPolyText = p; };
    std::string getPolyText() { return mPolyText; };
    void setFileName(QString f) { mFileName = f; };
    QString getFileName() { return mFileName; };
};


#endif
