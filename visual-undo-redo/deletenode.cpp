#include "deletenode.h"

DeleteNode::DeleteNode(ONode * node)
{
    classNode=new ONode();
    classNode=node;
    visibilityOff=false;
    visibilityOn=true;
}

DeleteNode::~DeleteNode()
{
    delete classNode;
}


void DeleteNode::undo()
{
    if(classNode->visibility==false)
        classNode->visibility=visibilityOn;
    else
        classNode->visibility=visibilityOff;

    classNode->setVisible(true);
}

void DeleteNode::redo()
{
    if(classNode->visibility==true)
        classNode->visibility=visibilityOff;
    else
        classNode->visibility=visibilityOn;

    classNode->setVisible(true);

}
