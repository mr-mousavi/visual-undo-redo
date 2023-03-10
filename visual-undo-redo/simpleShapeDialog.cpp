#include "simpleShapeDialog.h"
#include "ui_simpleshapedialog.h"

SimpleShapeDialog::SimpleShapeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SimpleShapeDialog)
{
    ui->setupUi(this);    

}

SimpleShapeDialog::~SimpleShapeDialog()
{
    delete ui;
}

void SimpleShapeDialog::showInfo(qint32  x, qint32  y, qint32  v)
{
    ui->x_lineEdit->setText(QString::number(x));
    ui->y_lineEdit->setText(QString::number(y));
    ui->v_lineEdit->setText(QString::number(v));
}

void SimpleShapeDialog::changed()
{
    x_number=ui->x_lineEdit->text().toInt();
    y_number=ui->y_lineEdit->text().toInt();
    v_number=ui->v_lineEdit->text().toInt();
}
