#include "resizeRectangle.h"

ResizeRectangle::ResizeRectangle(QWidget *parent) :
    QWidget(parent)
{
    this->setMaximumHeight(24);
    setMouseTracking(true);
}

ResizeRectangle::~ResizeRectangle()
{
}

void ResizeRectangle::enterEvent(QEvent *event)
{
    setCursor(Qt::SizeFDiagCursor);
    cursorPoint=mapFromParent(cursor().pos());
//    if(cursor().pos().x() >firstPoint.x() && cursor().pos().y() >firstPoint.y())
//    {
//    cursorPoint=mapFromParent(cursor().pos());
//    }

//    if(cursor().pos().x() >secondPoint.x() && cursor().pos().y() >firstPoint.y())
//    {
//    cursorPoint=mapFromParent(cursor().pos());
//    }

//    if(cursor().pos().x() >secondPoint.x() && cursor().pos().y() >secondPoint.y())
//    {
//    cursorPoint=mapFromParent(cursor().pos());
//    }

//    if(cursor().pos().x() >firstPoint.x() && cursor().pos().y() >secondPoint.y())
//    {
//    cursorPoint=mapFromParent(cursor().pos());
//    }

//    //for reversing resize
//    if(cursor().pos().x() < firstPoint.x() && cursor().pos().y() < firstPoint.y())
//    {
//    cursorPoint=mapFromParent(cursor().pos());
//    }

//    if(cursor().pos().x() < secondPoint.x() && cursor().pos().y() <firstPoint.y())
//    {
//    cursorPoint=mapFromParent(cursor().pos());
//    }

//    if(cursor().pos().x() < secondPoint.x() && cursor().pos().y() < secondPoint.y())
//    {
//    cursorPoint=mapFromParent(cursor().pos());
//    }

//    if(cursor().pos().x() < firstPoint.x() && cursor().pos().y() < secondPoint.y())
//    {
//    cursorPoint=mapFromParent(cursor().pos());
//    }

}

void ResizeRectangle::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()==Qt::LeftButton)
    {
//        qDebug()<<QString("width");
//        qDebug()<<(unsigned int)width();
//        qDebug()<<QString("height");
//        qDebug()<<(unsigned int) height();

    emit signal4ResizeRectangle(this);
    }
}

void ResizeRectangle::setFirstSecond(QPoint f, QPoint s)
{
    firstPoint=f;
    secondPoint=s;
}


