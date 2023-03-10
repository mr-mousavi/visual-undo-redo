/********************************************************************************
** Form generated from reading UI file 'simpleshapepolygon.ui'
**
** Created
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMPLESHAPEPOLYGON_H
#define UI_SIMPLESHAPEPOLYGON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_simpleShapePolygon
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *x_Label;
    QLineEdit *xLineEditObject;
    QHBoxLayout *horizontalLayout_2;
    QLabel *y_Label;
    QLineEdit *yLineEditObject;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *simpleShapePolygon)
    {
        if (simpleShapePolygon->objectName().isEmpty())
            simpleShapePolygon->setObjectName(QString::fromUtf8("simpleShapePolygon"));
        simpleShapePolygon->resize(214, 115);
        simpleShapePolygon->setModal(false);
        layoutWidget = new QWidget(simpleShapePolygon);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 191, 85));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        x_Label = new QLabel(layoutWidget);
        x_Label->setObjectName(QString::fromUtf8("x_Label"));

        horizontalLayout->addWidget(x_Label);

        xLineEditObject = new QLineEdit(layoutWidget);
        xLineEditObject->setObjectName(QString::fromUtf8("xLineEditObject"));

        horizontalLayout->addWidget(xLineEditObject);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        y_Label = new QLabel(layoutWidget);
        y_Label->setObjectName(QString::fromUtf8("y_Label"));

        horizontalLayout_2->addWidget(y_Label);

        yLineEditObject = new QLineEdit(layoutWidget);
        yLineEditObject->setObjectName(QString::fromUtf8("yLineEditObject"));

        horizontalLayout_2->addWidget(yLineEditObject);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout_3->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_3->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

#ifndef QT_NO_SHORTCUT
        x_Label->setBuddy(xLineEditObject);
        y_Label->setBuddy(yLineEditObject);
#endif // QT_NO_SHORTCUT

        retranslateUi(simpleShapePolygon);
        QObject::connect(okButton, SIGNAL(clicked()), simpleShapePolygon, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), simpleShapePolygon, SLOT(reject()));

        QMetaObject::connectSlotsByName(simpleShapePolygon);
    } // setupUi

    void retranslateUi(QDialog *simpleShapePolygon)
    {
        simpleShapePolygon->setWindowTitle(QApplication::translate("simpleShapePolygon", "simpleShapePolygon", 0));
        x_Label->setText(QApplication::translate("simpleShapePolygon", "x Position", 0));
        y_Label->setText(QApplication::translate("simpleShapePolygon", "y position", 0));
        okButton->setText(QApplication::translate("simpleShapePolygon", "OK", 0));
        cancelButton->setText(QApplication::translate("simpleShapePolygon", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class simpleShapePolygon: public Ui_simpleShapePolygon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMPLESHAPEPOLYGON_H
