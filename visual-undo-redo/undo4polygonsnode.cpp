#include "undo4polygonsnode.h"

Undo4PolygonsNode::Undo4PolygonsNode(ONode *node)
{
    classPolygonNode=new ONode();
    classPolygonNode=node;
    visibilityOff=false;
    visibilityOn=true;
}
Undo4PolygonsNode::~Undo4PolygonsNode()
{

}

void Undo4PolygonsNode::undo()
{
    if(classPolygonNode->visibility==false)
        classPolygonNode->visibility=visibilityOn;
    else
        classPolygonNode->visibility=visibilityOff;
    classPolygonNode->setVisible(true);

}

void Undo4PolygonsNode::redo()
{
    if(classPolygonNode->visibility==true)
        classPolygonNode->visibility=visibilityOff;
    else
        classPolygonNode->visibility=visibilityOn;
    classPolygonNode->setVisible(true);

}
