/********************************************************************************
** Form generated from reading UI file 'simpleshapedialog.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLESHAPEDIALOG_H
#define UI_SIMPLESHAPEDIALOG_H

#include <QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimpleShapeDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *x_label;
    QLineEdit *x_lineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *y_label;
    QLineEdit *y_lineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *speed;
    QLineEdit *v_lineEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *okButton;
    QPushButton *closeButton;

    void setupUi(QDialog *SimpleShapeDialog)
    {
        if (SimpleShapeDialog->objectName().isEmpty())
            SimpleShapeDialog->setObjectName(QString::fromUtf8("SimpleShapeDialog"));
        SimpleShapeDialog->resize(234, 173);
        layoutWidget = new QWidget(SimpleShapeDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 191, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        x_label = new QLabel(layoutWidget);
        x_label->setObjectName(QString::fromUtf8("x_label"));

        horizontalLayout->addWidget(x_label);

        x_lineEdit = new QLineEdit(layoutWidget);
        x_lineEdit->setObjectName(QString::fromUtf8("x_lineEdit"));

        horizontalLayout->addWidget(x_lineEdit);

        layoutWidget1 = new QWidget(SimpleShapeDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 191, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        y_label = new QLabel(layoutWidget1);
        y_label->setObjectName(QString::fromUtf8("y_label"));

        horizontalLayout_2->addWidget(y_label);

        y_lineEdit = new QLineEdit(layoutWidget1);
        y_lineEdit->setObjectName(QString::fromUtf8("y_lineEdit"));

        horizontalLayout_2->addWidget(y_lineEdit);

        layoutWidget2 = new QWidget(SimpleShapeDialog);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 90, 191, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        speed = new QLabel(layoutWidget2);
        speed->setObjectName(QString::fromUtf8("speed"));

        horizontalLayout_3->addWidget(speed);

        v_lineEdit = new QLineEdit(layoutWidget2);
        v_lineEdit->setObjectName(QString::fromUtf8("v_lineEdit"));

        horizontalLayout_3->addWidget(v_lineEdit);

        layoutWidget3 = new QWidget(SimpleShapeDialog);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(40, 140, 158, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget3);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_4->addWidget(okButton);

        closeButton = new QPushButton(layoutWidget3);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));

        horizontalLayout_4->addWidget(closeButton);

        QWidget::setTabOrder(x_lineEdit, y_lineEdit);
        QWidget::setTabOrder(y_lineEdit, v_lineEdit);
        QWidget::setTabOrder(v_lineEdit, okButton);
        QWidget::setTabOrder(okButton, closeButton);

        retranslateUi(SimpleShapeDialog);
        QObject::connect(closeButton, SIGNAL(clicked()), SimpleShapeDialog, SLOT(reject()));
        QObject::connect(okButton, SIGNAL(clicked()), SimpleShapeDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(SimpleShapeDialog);
    } // setupUi

    void retranslateUi(QDialog *SimpleShapeDialog)
    {
//        SimpleShapeDialog->setWindowTitle(QApplication::translate("SimpleShapeDialog", "SimpleShapeDialog", 0, QApplication::UnicodeUTF8));
//        x_label->setText(QApplication::translate("SimpleShapeDialog", "x position", 0, QApplication::UnicodeUTF8));
//        y_label->setText(QApplication::translate("SimpleShapeDialog", "y position", 0, QApplication::UnicodeUTF8));
//        y_lineEdit->setText(QString());
//        speed->setText(QApplication::translate("SimpleShapeDialog", "speed      ", 0, QApplication::UnicodeUTF8));
//        okButton->setText(QApplication::translate("SimpleShapeDialog", "OK", 0, QApplication::UnicodeUTF8));
//        closeButton->setText(QApplication::translate("SimpleShapeDialog", "Close", 0, QApplication::UnicodeUTF8));
        SimpleShapeDialog->setWindowTitle(QApplication::translate("SimpleShapeDialog", "SimpleShapeDialog", 0));
        x_label->setText(QApplication::translate("SimpleShapeDialog", "x position", 0));
        y_label->setText(QApplication::translate("SimpleShapeDialog", "y position", 0));
        y_lineEdit->setText(QString());
        speed->setText(QApplication::translate("SimpleShapeDialog", "speed      ", 0));
        okButton->setText(QApplication::translate("SimpleShapeDialog", "OK", 0));
        closeButton->setText(QApplication::translate("SimpleShapeDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SimpleShapeDialog: public Ui_SimpleShapeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLESHAPEDIALOG_H
