#ifndef ORECTANGLE_H
#define ORECTANGLE_H

#include <QtWidgets/QWidget>
#include <QMouseEvent>
#include <QPainter>
#include "simpleshaperectangle.h"
#include <QtWidgets/QMenu>
#include "resizeRectangle.h"
#include <QDebug>

class ORectAngle : public QWidget
{
    Q_OBJECT
public:
    explicit ORectAngle(QWidget *parent = 0); 
    ~ORectAngle();
       void mousePressEvent(QMouseEvent *event);
       void mouseReleaseEvent(QMouseEvent *event);
       void mouseMoveEvent(QMouseEvent *event);
       void mouseDoubleClickEvent(QMouseEvent *event);
       void drawRectangle(QPainter *p);
       QByteArray toByte();
       void fill(QDataStream *stream);

       QPoint lastFirstPoint;
       QPoint lastSecondPoint;
       QPoint firstPoint;
       QPoint secondPoint;
       bool visibility;
       simpleShapeRectAngle *getPop;
       QMenu* popup2;
       QAction *deleteRectangle;
       QAction *property;
       qint32 Id;
       QPoint clickPoint;

       qint32 x_temp;
       qint32 y_temp;
       qint32 width_temp;
       qint32 height_temp;
//       int width;
//       int height;
       ResizeRectangle *resize;
       QPoint clickPoint4Resize;

signals:
       void signalDeleteRectangle(ORectAngle *);
       void signalPropertiesRectangle(ORectAngle *);
       void signalDrawAgainRectangle(ORectAngle *);
       void signalUpdateRecangle();

private slots:
       void slotShowContextMenu(const QPoint &pt);
       void slotDeleteRectangleFunc();
       void slotPropertyRectangleFunc();
       void slot4ResizeRectangle(ResizeRectangle *obj);


};

#endif // ORECTANGLE_H
