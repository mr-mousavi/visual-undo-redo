#ifndef UNDODELETEPOLYGON_H
#define UNDODELETEPOLYGON_H

#include "action.h"
#include "onode.h"
#include <QVector>
#include "opolygon.h"

class UndoDeletePolygon : public Action
{
public:
    UndoDeletePolygon(ONode * node);
    ~UndoDeletePolygon();

    void undo();
    void redo();

    void checkPolygonNodes(QVector<OPolygon *> check, int i);
    ONode *classPolygonNodes;
    QVector<ONode *> temp4PolygonNodes;
    bool visibilityOff;
    bool visibilityOn;
    QVector <OPolygon *> tempallPoly;
    int index;
};

#endif // UNDODELETEPOLYGON_H
