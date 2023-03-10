#include "opolygon.h"

OPolygon::OPolygon(QWidget *parent) :
    QWidget(parent)
{
    visibility=true;
    Id=0;
    endToFirst=false;
}
//***********************************************************
OPolygon::~OPolygon()
{
}
//***********************************************************
QByteArray OPolygon::toByte()
{
    int falseCounter=0;
    int countNodes=onePoly.size();
    QByteArray array;
    QDataStream outPolygon(&array,QIODevice::WriteOnly);

    for(int i=0;i<onePoly.size();i++)
    {
        if(onePoly.at(i)->visibility==false)
        {
            falseCounter++;
        }
    }

    outPolygon <<falseCounter;

    outPolygon << countNodes;
    ONode *node;

    for(int i=0;i<onePoly.size();i++)
    {
        node=this->onePoly.at(i);

        if(node->visibility==true){
            outPolygon << node->toByte();
        }

    }
    if(falseCounter!=countNodes)
    {
        outPolygon <<(qint32) Id;
    }
return array;
}
//***********************************************************
void OPolygon::fill(QDataStream *stream)
{
    qint32 allByte;
    qint32 countNodes;
    qint32 nodeByte;
    int falseCounter;

    *stream >> allByte;
    *stream >>falseCounter;
    if(falseCounter<0)
    {
        falseCounter=0;
    }
    *stream >> countNodes;

        for(int j=0;j<countNodes-falseCounter;j++)
        {
            *stream >> nodeByte;
            ONode *node=new ONode();
            node->fill(stream);
            node->whichOne=polygonAction;
            onePoly.append(node);
        }
        if(falseCounter!=countNodes)
        {
        *stream >>this->Id;
        }
}
//***********************************************************
void OPolygon::setIsClosed(bool connect)
{
    endToFirst=connect;
}
//***********************************************************
bool OPolygon::isClosed()
{
    return endToFirst;
}
//***********************************************************
