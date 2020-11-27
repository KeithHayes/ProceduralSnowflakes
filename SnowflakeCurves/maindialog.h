#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include "flake.h"

#include <QDialog>

namespace Ui {

class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::MainDialog *ui;
    Flake mDialogData;

private slots:
    void on_btnDraw_clicked();
    void on_btnClear_clicked();
    void on_btnOpen_clicked();
    void on_btnSave_clicked();
    void on_btnBlack_clicked();
    void on_btnBlue_clicked();
    void on_btnGreen_clicked();
    void on_btnTeal_clicked();
    void on_btnDkGrey_clicked();
    void on_btnViolet_clicked();
    void on_btnLime_clicked();
    void on_btnAqua_clicked();
    void on_btnDkRed_clicked();
    void on_btnPlum_clicked();
    void on_btnBrown_clicked();
    void on_btnLtGrey_clicked();
    void on_btnOrange_clicked();
    void on_btnPink_clicked();
    void on_btnYellow_clicked();
    void on_btnWhite_clicked();
    void on_xOffset_valueChanged(int);
    void on_yOffset_valueChanged(int);
    void position(void);
    void on_spinScale_valueChanged(double);
    void on_spinSides_valueChanged(int);
    void on_spinLevel_valueChanged(int);
    void on_btnKoch_clicked();
    void on_btnSquare_clicked();
    void on_btnPeano_clicked();
    void on_btnPoly_clicked();
    void on_btnRandom_clicked();
    void on_spinPitch_valueChanged(double);
    void on_btnCircle_clicked(bool);
    void on_lineEdit_textChanged(const QString &arg1);


public:
    explicit MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

signals:
    void dialogPressed(int);
    void sendFlake(Flake);

public slots:
    void getFlake(void);
    void setSliders(float,float);

};

#endif
