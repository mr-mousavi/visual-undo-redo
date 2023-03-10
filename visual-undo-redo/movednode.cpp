#include "movednode.h"

movedNode::movedNode(ONode *node)
{
    classNode=new ONode();
    classNode=node;
}

void movedNode::undo()
{
    classNode->point->setX(x1);
    classNode->point->setY(y1);
    classNode->setGeometry(classNode->point->x()-5,classNode->point->y()-5,10,10);
    classNode->setVisible(true);
}

void movedNode::redo()
{
    classNode->point->setX(x2);
    classNode->point->setY(y2);
    classNode->setGeometry(classNode->point->x()-5,classNode->point->y()-5,10,10);
    classNode->setVisible(true);
}

void movedNode::beforeMoved(int x, int y)
{
    x1=x;
    y1=y;
}

void movedNode::afterMoved(int x, int y)
{
    x2=x;
    y2=y;
}
