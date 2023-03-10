#include "simpleshapepolygon.h"
#include "ui_simpleshapepolygon.h"

simpleShapePolygon::simpleShapePolygon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::simpleShapePolygon)
{
    ui->setupUi(this);
}

simpleShapePolygon::~simpleShapePolygon()
{
    delete ui;
}

void simpleShapePolygon::showInfo(qint32 x, qint32 y)
{
    ui->xLineEditObject->setText(QString::number(x));
    ui->yLineEditObject->setText(QString::number(y));
}

void simpleShapePolygon::changed()
{
    x_number=ui->xLineEditObject->text().toInt();
    y_number=ui->yLineEditObject->text().toInt();
}
