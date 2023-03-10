#ifndef SIMPLESHAPECIRCLE_H
#define SIMPLESHAPECIRCLE_H

#include <QtWidgets/QDialog>

namespace Ui {
    class simpleShapeCircle;
}

class simpleShapeCircle : public QDialog
{
    Q_OBJECT

public:
    explicit simpleShapeCircle(QWidget *parent = 0);
    ~simpleShapeCircle();

    void showInfo(qint32 x, qint32 y, qint32 r);
    void changed();
    qint32 x_number;
    qint32 y_number;
    qint32 radius_number;

private:
    Ui::simpleShapeCircle *ui;
};

#endif // SIMPLESHAPECIRCLE_H
