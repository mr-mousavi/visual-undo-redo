#ifndef SIMPLESHAPEPOLYGON_H
#define SIMPLESHAPEPOLYGON_H

#include <QtWidgets/QDialog>

namespace Ui {
    class simpleShapePolygon;
}

class simpleShapePolygon : public QDialog
{
    Q_OBJECT

public:
    explicit simpleShapePolygon(QWidget *parent = 0);
    ~simpleShapePolygon();

    void showInfo(qint32 x, qint32 y);
    void changed();
    qint32 x_number;
    qint32 y_number;
private:
    Ui::simpleShapePolygon *ui;
};

#endif // SIMPLESHAPEPOLYGON_H
