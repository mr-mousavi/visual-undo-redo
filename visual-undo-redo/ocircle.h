#ifndef OCIRCLE_H
#define OCIRCLE_H

#include <QtWidgets/QWidget>
#include <QMouseEvent>
#include <QPainter>
#include "simpleshapecircle.h"
#include <QtWidgets/QMenu>


class OCircle : public QWidget
{
//    friend QDataStream& operator<<( QDataStream& stream, const OCircle& circle);
//    friend QDataStream& operator>>( QDataStream& stream, OCircle& circle);
    Q_OBJECT

public:
    explicit OCircle(QWidget *parent = 0);
    OCircle(const OCircle & other);
    ~OCircle();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void drawCircle(QPainter *p);
    QByteArray toByte();
    void fill(QDataStream *stream);

    QPoint lastCenter;
    qint32 lastRadius;
    QPoint center;
    qint32 radius;
    qint32 Id;
    bool visibility;
    QMenu *popup2;
    simpleShapeCircle *getPop;
    QAction *deleteCircle;
    QAction *property;
    QPoint clickPoint;

    qint32 x_temp;
    qint32 y_temp;
    qint32 radius_temp;

signals:
    void signalDeleteCircle(OCircle *);
    void signalPropertyCircle(OCircle *);
    void signalDrawAgainCircle(OCircle *);
    void signalUpdateCircle();

private slots:
    void slotShowContextMenu(const QPoint &pt);
    void slotDeleteCircleFunc();
    void slotPropertyCircleFunc();
};

#endif // OCIRCLE_H
