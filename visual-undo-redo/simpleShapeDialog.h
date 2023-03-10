#ifndef SIMPLESHAPEDIALOG_H
#define SIMPLESHAPEDIALOG_H


#include <QtWidgets/QDialog>
#include <QString>
#include <QtWidgets/QMessageBox>

namespace Ui {
   class SimpleShapeDialog;
}

class SimpleShapeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SimpleShapeDialog(QWidget *parent = 0);
    ~SimpleShapeDialog();

    void showInfo(qint32 x, qint32 y, qint32 v);
    void changed();
    qint32 x_number;
    qint32 y_number;
    qint32 v_number;


private:
    Ui::SimpleShapeDialog *ui;

};

#endif // SIMPLESHAPEDIALOG_H
