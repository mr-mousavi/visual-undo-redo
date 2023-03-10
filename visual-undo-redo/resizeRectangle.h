#ifndef REASIZERECTANGLE_H
#define REASIZERECTANGLE_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

class ResizeRectangle : public QWidget
{
    Q_OBJECT
public:
    explicit ResizeRectangle(QWidget *parent = 0);
    ~ResizeRectangle();
    void enterEvent(QEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void setFirstSecond(QPoint f,QPoint s);
    QPoint cursorPoint;

private:
    QPoint firstPoint;
    QPoint secondPoint;
signals:
    void signal4ResizeRectangle(ResizeRectangle *);
public slots:
    
};

#endif // REASIZERECTANGLE_H
