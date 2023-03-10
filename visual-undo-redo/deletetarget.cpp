#include "deletetarget.h"


DeleteTarget::DeleteTarget(ONode *node)
{
    classNode=new ONode();
    visibilityOff=false;
    visibilityOn=true;
    classNode=node;

}

DeleteTarget::~DeleteTarget()
{
    delete classNode;
}

void DeleteTarget::undo()
{
        for(int i=0;i<tempOfTargetNodes.size();i++)
        {
            tempOfTargetNodes.at(i)->visibility=true;
            tempOfTargetNodes.at(i)->setVisible(true);
        }
}

void DeleteTarget::redo()
{
        for(int i=0;i<tempOfTargetNodes.size();i++)
        {
            tempOfTargetNodes.at(i)->visibility=false;
            tempOfTargetNodes.at(i)->setVisible(true);
        }
}

void DeleteTarget::checkNodes(QVector <ONode *> check)
{
    for(int i=0;i<check.size();i++)
    {
        if(check.at(i)->visibility==true)
        tempOfTargetNodes.append(check.at(i));
    }
}
