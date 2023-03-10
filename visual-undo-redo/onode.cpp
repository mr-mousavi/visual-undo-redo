#include "onode.h"

ONode::ONode(QWidget *parent)
    :QWidget(parent)
{
    visibility=true;
    setMouseTracking(true);
    x_temp=0;
    y_temp=0;
    v_temp=1;
    getPop=new SimpleShapeDialog();
    getPopPolygon=new simpleShapePolygon();
    popup2=new QMenu(this);
    popup1=new QMenu(this);
    deleteNode=new QAction("delete Node",this);
    deleteTarget=new QAction("delete Target",this);
    property=new QAction("property",this);
    deletePolygon=new QAction("delete Polygon",this);

    popup2->addAction(deleteNode);
    popup2->addAction(deleteTarget);
    popup2->addAction(property);

    popup1->addAction(deleteNode);
    popup1->addAction(deletePolygon);
    popup1->addAction(property);

    connect(this,SIGNAL(customContextMenuRequested(const QPoint &)),this,SLOT(showContextMenu(const QPoint &)));
    connect(deleteNode,SIGNAL(triggered()),this,SLOT(deleteNodeFunc()));
    connect(deleteTarget,SIGNAL(triggered()),this,SLOT(deleteTargetFunc()));
    connect(property,SIGNAL(triggered()),this,SLOT(propertyFunc()));
    connect(deletePolygon,SIGNAL(triggered()),this,SLOT(deletePolygonFunc()));
}
ONode::ONode(const ONode &)
{    
}
ONode::~ONode()
{
    delete popup2;
    delete popup1;
    delete deleteNode;
    delete deleteTarget;
    delete property;
    delete deletePolygon;
    delete getPop;
    delete getPopPolygon;
}
//***********************************************************
QByteArray ONode::toByte()
{
    QByteArray array;
    QDataStream outNode(&array,QIODevice::WriteOnly);

    outNode <<(qint32) point->x();
    outNode <<(qint32) point->y();

    return array;
}
//***********************************************************
void ONode::fill(QDataStream *stream)
{
    point=new QPoint;
    int x;
    int y;
    *stream >>x;
    *stream >>y;

    this->point->setX(x);
    this->point->setY(y);
}
//***********************************************************
void ONode::drawEllipse(QPainter *e)
{
    QPen p;
    p.setColor( Qt::white);
    e->setPen(p);
    e->drawEllipse(*point,3,3);
}
//***********************************************************
void ONode::mousePressEvent(QMouseEvent *event)
{
    if((event->buttons() == Qt::LeftButton) )
    {
        lastPoint=*point;
    }
    if(event->buttons() == Qt::RightButton)
    {
    showContextMenu(event->globalPos());
    }
}
//***********************************************************
void ONode::mouseReleaseEvent(QMouseEvent *event)
{
    emit signalDrawLines(this);
}
//***********************************************************
void ONode::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() == Qt::LeftButton ))
    {
        point->setX(cursor().pos().x());
        point->setY(cursor().pos().y());
        emit signalUpdate();
    }
}
//***********************************************************
void ONode::setSpeed(qint32 s)
{
    speed=s;
}
//***********************************************************
void ONode::mouseDoubleClickEvent(QMouseEvent * event)
{
    if(whichOne==targetAction)
    {
        emit signalPropertiesTarget(this);
    }
    if(whichOne==polygonAction)
    {
        emit signalPropertyPolygon(this);
    }
}
//****************slots**************************************
void ONode::showContextMenu(const QPoint &pt)
{
    if(whichOne==targetAction)
    {
        popup2->popup(pt);
    }
    if(whichOne==polygonAction)
    {
        popup1->popup(pt);
    }
}
//***********************************************************
void ONode::deleteNodeFunc()
{
        if(whichOne==targetAction)
        {
            emit signalDeleteNodeFunc(this);
        }
        if(whichOne==polygonAction)
        {
            emit signalDeletePolygonNodeFunc(this);
        }
}
//***********************************************************
void ONode::deleteTargetFunc()
{
    emit signalDeleteTargetFunc(this);
}
//***********************************************************
void ONode::propertyFunc()
{
    if(whichOne==targetAction)
    {
        emit signalPropertiesTarget(this);
    }
    if(whichOne==polygonAction)
    {
        emit signalPropertyPolygon(this);
    }
}
//***********************************************************
void ONode::deletePolygonFunc()
{
    emit signalDeletePolygonFunc(this);
}
