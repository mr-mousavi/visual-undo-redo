#ifndef ONODE_H
#define ONODE_H

#include <QtWidgets/QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "simpleShapeDialog.h"
#include "simpleshapepolygon.h"
#include <QtWidgets/QMessageBox>
#include <QString>
#include <QtWidgets/QMenu>

class OTarget;
enum targetPolygonEnum{polygonAction,targetAction};
class ONode : public QWidget

{
    Q_OBJECT
public:
   ONode(QWidget *parent = 0);
   ONode(const ONode &);
   ~ONode();


   QByteArray toByte();
   void fill(QDataStream *stream);
   void drawEllipse(QPainter *e);
   void mouseDoubleClickEvent(QMouseEvent *event);
   void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);

   QPoint lastPoint;
   QPoint *point;
   SimpleShapeDialog *getPop;
   QMenu* popup2;
   QAction *deleteNode;
   QAction *deleteTarget;
   QAction *property;
   QAction * deletePolygon;

   targetPolygonEnum whichOne;
   qint32 speed;
   qint32 x_temp;
   qint32 y_temp;
   qint32 v_temp;
   bool visibility;
   void setSpeed(qint32 s);

   qint32 x_polygonTemp;
   qint32 y_polygonTemp;
   QMenu *popup1;
   simpleShapePolygon *getPopPolygon;

signals:
   void signalDeleteNodeFunc(ONode *);
   void signalDeleteTargetFunc(ONode *);
   void signalPropertiesTarget(ONode *);
   void signalDrawLines(ONode *);
   void signalUpdate();
   void signalDeletePolygonFunc(ONode *);
   void signalDeletePolygonNodeFunc(ONode *);
   void signalPropertyPolygon(ONode *);

private slots:
    void showContextMenu(const QPoint &pt);
    void deleteNodeFunc();
    void deleteTargetFunc();
    void propertyFunc();
    void deletePolygonFunc();
};

#endif // ONODE_H
