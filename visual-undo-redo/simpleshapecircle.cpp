#include "simpleshapecircle.h"
#include "ui_simpleshapecircle.h"

simpleShapeCircle::simpleShapeCircle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simpleShapeCircle)
{
    ui->setupUi(this);

}

simpleShapeCircle::~simpleShapeCircle()
{
    delete ui;
}

void simpleShapeCircle::showInfo(qint32 x, qint32 y, qint32 r)
{
    ui->xCenterLineEditObject->setText(QString::number(x));
    ui->yCenterLineEditObject->setText(QString::number(y));
    ui->radiusLineEditObject->setText(QString::number(r));
}

void simpleShapeCircle::changed()
{
    x_number=ui->xCenterLineEditObject->text().toInt();
    y_number=ui->yCenterLineEditObject->text().toInt();
//    radius_number.setX(ui->radiusLineEditObject->text().toInt());
//    radius_number.setY(ui->radiusLineEditObject->text().toInt());
    radius_number=ui->radiusLineEditObject->text().toInt();
}
