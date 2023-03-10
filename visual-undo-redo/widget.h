#ifndef WIDGET_H
#define WIDGET_H

#include <QtCore>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QtWidgets/QGridLayout>
#include <QVector>
#include "otarget.h"
#include <QtWidgets/QMessageBox>
#include <QList>
#include "history.h"
#include "deletenode.h"
#include "deletetarget.h"
#include "changingproperty.h"
#include "movednode.h"
#include <QtWidgets/QFileDialog>
#include "orectangle.h"
#include "ocircle.h"
#include "opolygon.h"
#include "undo4deleterect.h"
#include "undo4propertyrect.h"
#include "undo4deletecircle.h"
#include "undo4propertycircle.h"
#include "undo4polygonsnode.h"
#include "undodeletepolygon.h"
#include "undo4propertypolygon.h"
#include "undo4movedcircle.h"
#include "undo4movedrectangle.h"
#include "QtWidgets/QSplitter"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    enum shapes{pathEnum,circleEnum,rectangleEnum,polygonEnum,nothing};
    void Popup(const QPoint& pt);
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);       //Paint events are sent to widgets that need to update
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void showAfterLoad();

private slots:
    void undoSlot();
    void redoSlot();
    void nodeSetting(ONode *node);
    void targetSetting(ONode *node);
    void property(ONode * properties);
    void rectangleSetting(ORectAngle * rangle);
    void propertyRectangle(ORectAngle *rangleProperties);
    void circleSetting(OCircle *cir);
    void propertyCircle(OCircle *circleProperties);
    void polygonNodeSetting(ONode * node);
    void polygonSetting(ONode * node);
    void propertyPolygon(ONode * polygonProperty);
    void saveWindow();
    void loadWindow();
    void drawAgain(ONode * again);
    void drawAgainCircle(OCircle * againCircle);
    void drawAgainRectngle(ORectAngle *againRect);
    void addPath();
    void slotUpdate();
    void slotUpdateRectangl();
    void slotUpdateCircle();
    void drawRectangle();
    void drawCircle();
    void drawPolygon();

private:
        qint32 generateId();
        qint32 generateId4Rect();
        qint32 generateId4Circle();
        qint32 generateId4Polygon();
        void drawLines(QPainter *l);
        void drawRectAngles(QPainter *l);
        void drawCircles(QPainter *l);
        void drawPolygons(QPainter *l);

        QVector<ONode*> tempEllise;
        QVector<ONode*> tempLine;
        QVector<ONode*> tempLine2;        // for drawing line because drawlines with vector-> Draws a line for each pair of points in the vector
        QVector<QPoint> tempEllisePoint;
        QVector<QPoint> tempLinePoint;
        QVector<QPoint> tempLine2Point;   // for drawing line because drawlines with vector-> Draws a line for each pair of points in the vector

        shapes whichShape;
        qint32 LastId;
        qint32 LastId4Rect;
        qint32 LastId4Circle;
        qint32 LastId4Polygon;
        bool flag;
        bool flag4Click;
        bool flag4Rectangle;
        bool flag4Circle;
        bool flag4Polygon;
        bool flag4ControlPolygon;

        DeleteNode * objNode;
        Undo4DeleteRect * objRect;
        Undo4DeleteCircle * objCircle;
        Undo4PolygonsNode *objPolygonNode;
        OTarget * points; //points pointer havie yek copy az azaye dade va tavabe ozve OCordinate ra darad,va vaghti ba pos() por mishavad dar asl azaye copy por mishavand na khode azaye klasse OCordinate.
        ONode *thisPoint;
        QVector<OTarget*> allCoordinate;

        ORectAngle *rect;
        QVector<ORectAngle*> allRectangle;       //record rectangle info in this vector
        int xRect,yRect,wRect,hRect;   // these variable are for drawing recangle,not for all rectangle
//        qint32 a=0,b=0,c=0;
        qint32 diameter;

        OCircle *circle;
        qint32 r;
        QPoint circleCenter;
        QVector <OCircle *> allCircle;

        OPolygon * polygon;
        ONode * polyNode;
        QVector <OPolygon *> allPolygon;

};

#endif // WIDGET_H
