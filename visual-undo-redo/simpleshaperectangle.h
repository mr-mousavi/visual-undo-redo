#ifndef SIMPLESHAPERECTANGLE_H
#define SIMPLESHAPERECTANGLE_H

#include <QtWidgets/QDialog>

namespace Ui {
    class simpleShapeRectAngle;
}

class simpleShapeRectAngle : public QDialog
{
    Q_OBJECT

public:
    explicit simpleShapeRectAngle(QWidget *parent = 0);
    ~simpleShapeRectAngle();

    void showInfo(qint32 x,qint32 y,qint32 width,qint32 height);
    void changed();
    int x_Number,y_Number,width_Number,height_Number;

private:
    Ui::simpleShapeRectAngle *ui;
};

#endif // SIMPLESHAPERECTANGLE_H
