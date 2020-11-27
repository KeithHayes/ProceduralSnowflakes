#include "maindialog.h"
#include "ui_maindialog.h"
#include "misc.h"
#include <string>
#include <iostream>
#include <QFileDialog>

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    QFile stylesheet_file(":/stylesheet/qss/stylesheet.css");
    stylesheet_file.open(QFile::ReadOnly);
    QString stylesheet = QLatin1String(stylesheet_file.readAll());
    setStyleSheet(stylesheet);
    mDialogData.setXmax(1);
    mDialogData.setYmax(1);
    mDialogData.setXoffset(0);
    mDialogData.setYoffset(0);
    ui->xOffset->setValue(0);
    ui->yOffset->setValue(0);
    mDialogData.setPitch(0);
    mDialogData.setSides(INITIATOR_DEFAULT);
    mDialogData.setLevels(LEVEL_DEFAULT);
    mDialogData.setScale(SCALE_DEFAULT);
    ui->spinSides->setValue(INITIATOR_DEFAULT);
    ui->spinLevel->setValue(LEVEL_DEFAULT);
    ui->spinScale->setValue(SCALE_DEFAULT);
    mDialogData.setType(ShapeType::koch);
    mDialogData.setColor(GOLD);
    mDialogData.setCircle(false);
    mDialogData.setPolyText(POLY_TEXT);
    ui->lineEdit->setText(POLY_TEXT);
    position();
}

MainDialog::~MainDialog() {
    delete ui;
}

void MainDialog::on_btnDraw_clicked() {
    emit dialogPressed(0);
}
void MainDialog::on_btnClear_clicked() {
    emit dialogPressed(1);
}
void MainDialog::on_btnOpen_clicked() {
    mDialogData.setFileName(QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath()));
    emit dialogPressed(2);
}
void MainDialog::on_btnSave_clicked() {
    emit dialogPressed(3);
}

void MainDialog::getFlake(void) {
    emit sendFlake(mDialogData);
}

void MainDialog::setSliders(float sizeX,float sizeY) {
    float xMax = 100*((sizeX>sizeY) ? (sizeX/sizeY) : 1.0);
    float yMax = 100*((sizeY>sizeX) ? (sizeY/sizeX) : 1.0);
    ui->xOffset->setMaximum(xMax);
    ui->yOffset->setMaximum(yMax);
    ui->xOffset->setMinimum(-xMax);
    ui->yOffset->setMinimum(-yMax);
}

void MainDialog::on_btnBlack_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #000000;");
    mDialogData.setColor(BLACK);
}
void MainDialog::on_btnBlue_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #0000aa;");
    mDialogData.setColor(BLUE);
}
void MainDialog::on_btnGreen_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #00aa00;");
    mDialogData.setColor(GREEN);
}
void MainDialog::on_btnTeal_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #00aaaa;");
    mDialogData.setColor(TEAL);
}
void MainDialog::on_btnDkGrey_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #555555;");
    mDialogData.setColor(DKGREY);
}
void MainDialog::on_btnViolet_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #5555ff;");
    mDialogData.setColor(VIOLET);
}
void MainDialog::on_btnLime_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #55ff55;");
    mDialogData.setColor(LIME);
}
void MainDialog::on_btnAqua_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #55ffff;");
    mDialogData.setColor(AQUA);
}
void MainDialog::on_btnDkRed_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #aa0000;");
    mDialogData.setColor(DKRED);
}
void MainDialog::on_btnPlum_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #aa00aa;");
    mDialogData.setColor(PLUM);
}
void MainDialog::on_btnBrown_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #aa5500;");
    mDialogData.setColor(BROWN);
}
void MainDialog::on_btnLtGrey_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #aaaaaa;");
    mDialogData.setColor(LTGREY);
}
void MainDialog::on_btnOrange_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #ff5555;");
    mDialogData.setColor(ORANGE);
}
void MainDialog::on_btnPink_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #ff55ff;");
    mDialogData.setColor(PINK);
}
void MainDialog::on_btnYellow_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #ffff55;");
    mDialogData.setColor(YELLOW);
}
void MainDialog::on_btnWhite_clicked() {
    ui->selectedColor->setStyleSheet("background-color: #ffffff;");
    mDialogData.setColor(WHITE);
}

void MainDialog::on_xOffset_valueChanged(int value) {
    mDialogData.setXoffset((float)(value + 0.5)/100);
    position();
}
void MainDialog::on_yOffset_valueChanged(int value) {
    mDialogData.setYoffset((float)(value + 0.5)/100);
    position();
}
void MainDialog::position(void){
    char xBuffer[10], yBuffer[10];
    char outbuffer[20];
    sprintf(xBuffer, "%6.2f",mDialogData.getXoffset());
    sprintf(yBuffer, "%6.2f",mDialogData.getYoffset());
    sprintf(outbuffer,"(%s, %s)",xBuffer,yBuffer);
    ui->offset->setText(outbuffer);
}


void MainDialog::on_spinScale_valueChanged(double value) {
    mDialogData.setScale((float)(value + 0.00499));
}
void MainDialog::on_spinPitch_valueChanged(double pitch) {
    mDialogData.setPitch(pitch);
}
void MainDialog::on_spinSides_valueChanged(int sides) {
    mDialogData.setSides(sides);
}
void MainDialog::on_spinLevel_valueChanged(int levels) {
    mDialogData.setLevels(levels);
}


void MainDialog::on_btnKoch_clicked() {
    mDialogData.setType(ShapeType::koch);
}
void MainDialog::on_btnSquare_clicked() {
    mDialogData.setType(ShapeType::square);
}
void MainDialog::on_btnPeano_clicked() {
    mDialogData.setType(ShapeType::peano);
}
void MainDialog::on_btnPoly_clicked() {
    mDialogData.setType(ShapeType::poly);
}
void MainDialog::on_btnRandom_clicked() {
    mDialogData.setType(ShapeType::random);
}

void MainDialog::on_btnCircle_clicked(bool checked) {
    mDialogData.setCircle(checked);
}

void MainDialog::on_lineEdit_textChanged(const QString &text) {
    std::string stdText = text.toLocal8Bit().constData();
    mDialogData.setPolyText(stdText);
}
