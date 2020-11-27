#include "viewscreen.h"
#include "graphics.h"
#include "snowflake.h"
#include "maindialog.h"
#include "rand.h"
#include <QPaintEvent>
#include <QMessageBox>
#include <QFile>
#include <string>

ViewScreen::ViewScreen(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor (0,0,0)
{
    mControls = new MainDialog(this);
    QObject::connect(mControls, SIGNAL(dialogPressed(int)), this, SLOT(dialogButton(int)));
    QObject::connect(this, SIGNAL(updateFlake(void)), mControls, SLOT(getFlake(void)));
    QObject::connect(mControls, SIGNAL(sendFlake(Flake)), this, SLOT(receiveFlake(Flake)));
    QObject::connect(this, SIGNAL(updateSliders(float,float)), mControls, SLOT(setSliders(float,float)));
    mSizeX = 800;
    mSizeY = 800;
    mImage = QPixmap(mSizeX, mSizeY).toImage();
    mControls->show();
    paintArea();
}

void ViewScreen::dialogButton(int dialogPressed) {
    int showstring = dialogPressed;
    switch (showstring) {
    case 0:
        paintArea();
        break;
    case 1:
        clearPaintArea();
        break;
    case 2:
        openFile();
        break;
    case 3:
        saveFile();
        break;
    case 4:
        QMessageBox::information(this,"title","ToDo Button");
        break;
    default:
        break;
    }
}

void ViewScreen::receiveFlake(Flake flake) {
    mFlakeData = flake;
}

QSize ViewScreen::minimumSizeHint() const {
    return QSize(800,800);
}

QSize ViewScreen::sizeHint() const {
    return QSize(800,800);
}

void ViewScreen::clearPaintArea(void) {
    QPainter painter(&mImage);
    painter.setBrush(mBackgroundColor);
    painter.drawRect(this->rect());
    QWidget::update();
}

void ViewScreen::resizeEvent(QResizeEvent *event) {
    mSizeX = width();
    mSizeY = height();
    updateSliders(mSizeX,mSizeY);
    if (mSizeX>mImage.width()||mSizeY>mImage.height()) {
        int newWidth = qMax(mSizeX + 128, mImage.width());
        int newHeight = qMax(mSizeY + 128, mImage.height());
        resizeImage(&mImage, QSize(newWidth, newHeight));
        update();
    }
    QWidget::resizeEvent(event);
}

void ViewScreen::resizeImage(QImage *image, const QSize &newSize) {
    if (image->size() == newSize) return;
    QImage newImage(newSize, QImage::Format_RGB32);
    newImage.fill(qRgb(0, 0, 0));
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), *image);
    *image = newImage;
}

bool ViewScreen::openFile(void) {
    updateFlake();
    QImage loadedImage;
    if (!loadedImage.load(mFlakeData.getFileName())) return false;
    QSize newSize = loadedImage.size().expandedTo(size());
    resizeImage(&loadedImage, newSize);
    mImage = loadedImage;
    update();
    return true;
}

bool ViewScreen::saveFile(void) {
    QString format="png";
    const QByteArray fileFormat = format.toUtf8();
    QString initialPath = QDir::currentPath() + "/untitled." + fileFormat;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
        initialPath,
        tr("%1 Files (*.%2);;All Files (*)")
        .arg(QString::fromLatin1(fileFormat.toUpper()))
        .arg(QString::fromLatin1(fileFormat)));
    if (fileName.isEmpty()) { return false; }
    else {
        QImage visibleImage = mImage;
        resizeImage(&visibleImage, size());
        if (visibleImage.save(fileName, fileFormat)) {
            return true;
        } else { return false; }
    }
}

void ViewScreen::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    QRect touched = event->rect();
    painter.drawImage(touched, mImage, touched);
}

void ViewScreen::paintArea(void) {
    QPainter painter(&mImage);
    painter.setRenderHint(QPainter::Antialiasing, true);
    updateFlake();
    int rand_level=mFlakeData.getLevels();
    ShapeType newtype;
    if(mFlakeData.getType()==ShapeType::random) {
        Rand randgen = Rand();
        randgen.timeSeed();
        newtype = ShapeType::koch;
        rand_level=1;
        for(int i=0;i<9;i++) { // original random mode generated flakedata and looped 20 times
            if(++rand_level>4) {
                rand_level=2;
                mFlakeData.setSides(randgen.getRand(10)+3);
                if(mFlakeData.getType()==ShapeType::peano) { newtype = ShapeType::square; }
                else if(mFlakeData.getType()==ShapeType::square) { newtype = ShapeType::peano; }
                else { newtype = ShapeType::square; }
            }
            mFlakeData.setCircle(!mFlakeData.getCircle());
            mFlakeData.setLevels(rand_level);
            mFlakeData.setType(newtype);
            float Xoffset = 2*((mSizeX>mSizeY) ? (mSizeX/mSizeY) : 1.0)*randgen.getRand()-1;
            float Yoffset = 2*((mSizeY>mSizeX) ? (mSizeY/mSizeX) : 1.0)*randgen.getRand()-1;
            mFlakeData.setXoffset(Xoffset);
            mFlakeData.setYoffset(Yoffset);
            mFlakeData.setScale(1.25*randgen.getRand()*mFlakeData.getScale()+0.33);
            mFlakeData.setPitch(PI*randgen.getRand());
            std::string colors[] = COLORS;
            int index = (int)randgen.getRand(16);
            mFlakeData.setColor(colors[index]);
            Snowflake newshape(Point(mSizeX,mSizeY), painter, mFlakeData);
            newshape.process();
            QWidget::update();
        }
    }
    else {
        Snowflake newshape(Point(mSizeX,mSizeY), painter, mFlakeData);
        newshape.process();
        QWidget::update();
    }
}
