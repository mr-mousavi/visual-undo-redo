#include "undodeletepolygon.h"

UndoDeletePolygon::UndoDeletePolygon(ONode * node)
{
    classPolygonNodes=new ONode();
    classPolygonNodes=node;
    visibilityOff=false;
    visibilityOn=true;

}
UndoDeletePolygon::~UndoDeletePolygon()
{
    delete classPolygonNodes;
}
void UndoDeletePolygon::undo()
{
    for(int i=0;i<temp4PolygonNodes.size();i++)
    {
        temp4PolygonNodes.at(i)->visibility=true;
        temp4PolygonNodes.at(i)->setVisible(true);
        tempallPoly.at(index)->setIsClosed(true);
    }
}
void UndoDeletePolygon::redo()
{
    for(int i=0;i<temp4PolygonNodes.size();i++)
    {
        temp4PolygonNodes.at(i)->visibility=false;
        temp4PolygonNodes.at(i)->setVisible(true);
        tempallPoly.at(index)->setIsClosed(false);
    }
}
void UndoDeletePolygon::checkPolygonNodes(QVector<OPolygon *> check,int i)
{
        tempallPoly=check;
        index=i;
//    for(int i=0;i<check.size();i++)
//    {
//        if(check.at(i)->visibility==true)
//        temp4PolygonNodes.append(check.at(i)->onePoly);
//    }
    if(check.at(i)->visibility==true)
//       temp4PolygonNodes.append(check.at(i)->onePoly);
        temp4PolygonNodes=check.at(i)->onePoly;
}
