#include "undo4propertypolygon.h"

Undo4PropertyPolygon::Undo4PropertyPolygon(ONode * node)
{
    classPolygonNodes=new ONode();
    classPolygonNodes=node;
}
Undo4PropertyPolygon::~Undo4PropertyPolygon()
{
    delete classPolygonNodes;
}
void Undo4PropertyPolygon::undo()
{
    classPolygonNodes->point->setX(x);
    classPolygonNodes->point->setY(y);
}
void Undo4PropertyPolygon::redo()
{
    classPolygonNodes->point->setX(x2);
    classPolygonNodes->point->setY(y2);
}
void Undo4PropertyPolygon::firstNode(int a, int b)
{
    x=a;
    y=b;
}
void Undo4PropertyPolygon::secondNode(int a, int b)
{
    x2=a;
    y2=b;
}
