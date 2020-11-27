#ifndef SCREENAREA_H
#define SCREENAREA_H
#include "flake.h"
#include "maindialog.h"
#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QtWidgets>


class ViewScreen : public QWidget
{
    Q_OBJECT

private:
    QColor mBackgroundColor;
    QImage mImage;
    MainDialog* mControls;
    Flake mFlakeData;
    int mSizeX;
    int mSizeY;

protected:

void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
void paintArea(void);
void clearPaintArea(void);
void resizeEvent(QResizeEvent *event) override;
void resizeImage(QImage *, const QSize &);
bool openFile(void);
bool saveFile(void);

public:
    explicit ViewScreen(QWidget *parent = nullptr);
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

signals:
    void updateFlake(void);
    void updateSliders(float,float);

public slots:
    void dialogButton(int);
    void receiveFlake(Flake);
    int getXsize(void){ return mSizeX; };
    int getYsize(void){ return mSizeY; };
};

#endif
