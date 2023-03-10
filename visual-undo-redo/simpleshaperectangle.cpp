#include "simpleshaperectangle.h"
#include "ui_simpleshaperectangle.h"

simpleShapeRectAngle::simpleShapeRectAngle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simpleShapeRectAngle)
{
    ui->setupUi(this);
}

simpleShapeRectAngle::~simpleShapeRectAngle()
{
    delete ui;
}

void simpleShapeRectAngle::showInfo(qint32 x, qint32 y, qint32 width, qint32 height)
{
    ui->xLineEditObject->setText(QString::number(x));
    ui->yLineEditObject->setText(QString::number(y));
    ui->widthLineEditObject->setText(QString::number(width));
    ui->heightLineEditObject->setText(QString::number(height));
}

void simpleShapeRectAngle::changed()
{
    x_Number=ui->xLineEditObject->text().toInt();
    y_Number=ui->yLineEditObject->text().toInt();
    width_Number=ui->widthLineEditObject->text().toInt();
    height_Number=ui->heightLineEditObject->text().toInt();
}
