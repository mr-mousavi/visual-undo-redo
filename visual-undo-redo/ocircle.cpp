#include "ocircle.h"

OCircle::OCircle(QWidget *parent) :
    QWidget(parent)
{
    x_temp=0;
    y_temp=0;
    radius=0;
    Id=0;
    visibility=true;
    setMouseTracking(true);

    getPop=new simpleShapeCircle();
    popup2=new QMenu(this);
    deleteCircle=new QAction("delete Circle",this);
    property=new QAction("property",this);


    popup2->addAction(deleteCircle);
    popup2->addAction(property);

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,SIGNAL(customContextMenuRequested(const QPoint &)),this,SLOT(slotShowContextMenu(const QPoint &)));

    connect(deleteCircle,SIGNAL(triggered()),this,SLOT(slotDeleteCircleFunc()));
    connect(property,SIGNAL(triggered()),this,SLOT(slotPropertyCircleFunc()));
}
OCircle::OCircle(const OCircle &other)
{
}
OCircle::~OCircle()
{
    delete popup2;
    delete deleteCircle;
    delete property;
    delete getPop;
}
//***********************************************************
void OCircle::slotShowContextMenu(const QPoint &pt)
{
    popup2->popup(pt);
}
//***********************************************************
void OCircle::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::RightButton)
    {
    slotShowContextMenu(event->globalPos());
    }

    if(event->buttons() ==Qt::LeftButton)
    {
        clickPoint=mapToGlobal(event->pos());
        lastCenter=center;
        lastRadius=radius;
    }
}
//***********************************************************
void OCircle::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() == Qt::LeftButton ))
    {
    center.setX(cursor().pos().x());
    center.setY(cursor().pos().y());
    }
    emit signalUpdateCircle();
}
//***********************************************************
void OCircle::mouseReleaseEvent(QMouseEvent *event)
{
    emit signalDrawAgainCircle(this);
}
//***********************************************************
void OCircle::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit signalPropertyCircle(this);
}
//***********************************************************
void OCircle::drawCircle(QPainter *p)
{
    QLinearGradient myGradient;
    QPainterPath myPath;
    p->drawPath(myPath);
    p->drawEllipse(center,radius,radius);
}
//***********************************************************
void OCircle::slotDeleteCircleFunc()
{
    emit signalDeleteCircle(this);
}
//***********************************************************
void OCircle::slotPropertyCircleFunc()
{
    emit signalPropertyCircle(this);
}
//***********************************************************
QByteArray OCircle::toByte()
{

    QByteArray array;
    QDataStream outCircle(&array,QIODevice::WriteOnly);

    outCircle<<(qint32) center.x();
    outCircle<<(qint32) center.y();
    outCircle<<(qint32) radius;
    outCircle<<(qint32) Id;

    return array;
}
//***********************************************************
void OCircle::fill(QDataStream *stream)
{
    int size,x,y,r,id;
    *stream >>size>>x>>y>>r>>id;

    this->center.setX(x);
    this->center.setY(y);
    this->radius=r;
    this->Id=id;
}
//***********************************************************
//QDataStream & operator<<(QDataStream &streamWrite, const OCircle& circle)
//{
//    return streamWrite <<circle.center <<circle.radius <<circle.Id;
//}
////***********************************************************
//QDataStream & operator>>(QDataStream &streamRead, OCircle& circle)
//{
//    return streamRead >>circle.center >>circle.radius >>circle.Id;
//}
