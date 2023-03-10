#include "otarget.h"

OTarget::OTarget()
{
    speed=1;
}
//***********************************************************
QByteArray OTarget::toByte()
{
    int falseCounter=0;
    int countNodes=coordinate.size();
    QByteArray array;
    QDataStream outTarget(&array,QIODevice::WriteOnly);

    for(int i=0;i<coordinate.size();i++)
    {
        if(coordinate.at(i)->visibility==false)
        {
            falseCounter++;
        }
    }

    outTarget <<falseCounter;

    outTarget << countNodes;
    ONode *node;

    for(int i=0;i<coordinate.size();i++)
    {
        node=this->coordinate.at(i);

        if(node->visibility==true){
            outTarget << node->toByte();
        }

    }
    if(falseCounter!=countNodes)
    {
        outTarget <<(qint32) Id;
        outTarget <<(qint32) speed;
    }
return array;
}
//***********************************************************
void OTarget::fill(QDataStream *stream)
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
            node->whichOne=targetAction;
            coordinate.append(node);
        }/*polygonAction,targetAction*/
        if(falseCounter!=countNodes)
        {
        *stream >>this->Id;
        *stream >>this->speed;
        }
}
