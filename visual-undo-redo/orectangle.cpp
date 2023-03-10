#include "orectangle.h"

ORectAngle::ORectAngle(QWidget *parent) :
    QWidget(parent)
{
    visibility=true;
       setMouseTracking(true);
       x_temp=0;
       y_temp=0;
       width_temp=0;
       height_temp=0;

       Id=0;
       getPop=new simpleShapeRectAngle();
       popup2=new QMenu(this);
       deleteRectangle=new QAction("delete RectAngle",this);
       property=new QAction("property",this);


       popup2->addAction(deleteRectangle);
       popup2->addAction(property);

       setContextMenuPolicy(Qt::CustomContextMenu);
       connect(this,SIGNAL(customContextMenuRequested(const QPoint &)),this,SLOT(slotShowContextMenu(const QPoint &)));

       connect(deleteRectangle,SIGNAL(triggered()),this,SLOT(slotDeleteRectangleFunc()));
       connect(property,SIGNAL(triggered()),this,SLOT(slotPropertyRectangleFunc()));

}

ORectAngle::~ORectAngle()
{
delete popup2;
delete deleteRectangle;
delete property;
delete getPop;
}
//***********************************************************
void ORectAngle::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::RightButton)
    {
    slotShowContextMenu(event->globalPos());
    }
    if(event->buttons() == Qt::LeftButton)
    {
       clickPoint=mapToGlobal(event->pos());
       lastFirstPoint=firstPoint;
       lastSecondPoint=secondPoint;
    }
}
//***********************************************************
void ORectAngle::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() == Qt::LeftButton ))
    {

        firstPoint.setX(firstPoint.x()+(cursor().pos().x()-clickPoint.x()));
        firstPoint.setY(firstPoint.y()+(cursor().pos().y()-clickPoint.y()));
        secondPoint.setX(secondPoint.x()+(cursor().pos().x()-clickPoint.x()));
        secondPoint.setY(secondPoint.y()+(cursor().pos().y()-clickPoint.y()));

        clickPoint=cursor().pos();
        emit signalUpdateRecangle();
        resize->setFirstSecond(this->firstPoint,this->secondPoint);
    }

}
//***********************************************************
void ORectAngle::mouseReleaseEvent(QMouseEvent *event)
{
    emit signalDrawAgainRectangle(this);
}
//***********************************************************
void ORectAngle::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit signalPropertiesRectangle(this);
}
//***********************************************************
void ORectAngle::drawRectangle(QPainter *p)
{
    p->drawRect(firstPoint.x(),firstPoint.y(),(secondPoint.x()-firstPoint.x()),(secondPoint.y()-firstPoint.y()));

    //for resize
    resize=new ResizeRectangle(this);
    resize->setGeometry(width()-5,height()-5,5,5);
    resize->setVisible(true);
    connect(resize,SIGNAL(signal4ResizeRectangle(ResizeRectangle*)),this,SLOT(slot4ResizeRectangle(ResizeRectangle*)));

}
//***********************************************************
void ORectAngle::slotShowContextMenu(const QPoint &pt)
{
    popup2->popup(pt);
}
//***********************************************************
void ORectAngle::slotDeleteRectangleFunc()
{
    emit signalDeleteRectangle(this);
}
//***********************************************************
void ORectAngle::slotPropertyRectangleFunc()
{
    emit signalPropertiesRectangle(this);
}
//***********************************************************
QByteArray ORectAngle::toByte()
{
    QByteArray array;
    QDataStream outRecangle(&array,QIODevice::WriteOnly);

    outRecangle<<(qint32) firstPoint.x();
    outRecangle<<(qint32) firstPoint.y();
    outRecangle<<(qint32) secondPoint.x();
    outRecangle<<(qint32) secondPoint.y();
    outRecangle<<(qint32) Id;

    return array;
}
//***********************************************************
void ORectAngle::fill(QDataStream *stream)
{
    int size,x,y,w,h,id;
    *stream >>size>>x>>y>>w>>h>>id;

    this->firstPoint.setX(x);
    this->firstPoint.setY(y);
    this->secondPoint.setX(w);
    this->secondPoint.setY(h);
    this->Id=id;
}
//***********************************************************
void ORectAngle::slot4ResizeRectangle(ResizeRectangle *obj)
{
    clickPoint4Resize=obj->cursorPoint;

    if(cursor().pos().x() > firstPoint.x()+10 && cursor().pos().y() > firstPoint.y())
    {
        //changing Rectangle size
        if(this->firstPoint.x()<this->secondPoint.x()  &&  this->firstPoint.y() <this->secondPoint.y())   //top left to bottom right
        {
            this->secondPoint.setX(cursor().pos().x());
            this->secondPoint.setY(cursor().pos().y()-20);
        }
        if(this->firstPoint.x()>this->secondPoint.x()  &&  this->firstPoint.y() < this->secondPoint.y())  //top right to bottom left
        {
            this->firstPoint.setX(cursor().pos().x());
            this->secondPoint.setY(cursor().pos().y()-20);
        }
        if(this->firstPoint.x()>this->secondPoint.x() && this->firstPoint.y() >this->secondPoint.y())    //bottom right to top left
        {
            this->firstPoint.setX(cursor().pos().x());
            this->firstPoint.setY(cursor().pos().y()-20);
        }
        if(this->firstPoint.x()<this->secondPoint.x() && this->firstPoint.y() >this->secondPoint.y())    //bottom left to top right
        {
            this->secondPoint.setX(cursor().pos().x());
            this->firstPoint.setY(cursor().pos().y()-20);
        }
    }


    //set Geometry of Rectangle
    if(this->firstPoint.x()<this->secondPoint.x()  &&  this->firstPoint.y() <this->secondPoint.y())   //top left to bottom right
    {
        this->setGeometry(this->firstPoint.x(),
                        this->firstPoint.y(),
                        this->secondPoint.x()-this->firstPoint.x(),
                        this->secondPoint.y()-this->firstPoint.y());
    }
    if(this->firstPoint.x()>this->secondPoint.x()  &&  this->firstPoint.y() < this->secondPoint.y())  //top right to bottom left
    {
        this->setGeometry(this->secondPoint.x(),
                          this->firstPoint.y(),
                          this->firstPoint.x()-this->secondPoint.x(),
                          this->secondPoint.y()-this->firstPoint.y());
    }
    if(this->firstPoint.x()>this->secondPoint.x() && this->firstPoint.y() >this->secondPoint.y())    //bottom right to top left
    {
        this->setGeometry(this->secondPoint.x(),
                          this->secondPoint.y(),
                          this->firstPoint.x()-this->secondPoint.x(),
                          this->firstPoint.y()-this->secondPoint.y());
    }
    if(this->firstPoint.x()<this->secondPoint.x() && this->firstPoint.y() >this->secondPoint.y())    //bottom left to top right
    {
        this->setGeometry(this->firstPoint.x(),
                          this->secondPoint.y(),
                          this->secondPoint.x()-this->firstPoint.x(),
                          this->firstPoint.y()-this->secondPoint.y());
    }
    emit signalUpdateRecangle();

}
