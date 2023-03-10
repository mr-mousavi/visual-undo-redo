#include "changingproperty.h"

ChangingProperty::ChangingProperty(ONode * node)
{
    classNode=new ONode();
    classNode=node;
}
ChangingProperty::~ChangingProperty()
{
    delete classNode;
}
void ChangingProperty::undo()
{
    classNode->point->setX(x);
    classNode->point->setY(y);
    classNode->speed=s;
}
void ChangingProperty::redo()
{
    classNode->point->setX(x2);
    classNode->point->setY(y2);
    classNode->speed=s2;
}
void ChangingProperty::firstNode(int a,int b,int c)
{
    x=a;
    y=b;
    s=c;
}
void ChangingProperty::secondNode(int a, int b, int c)
{
    x2=a;
    y2=b;
    s2=c;
}
