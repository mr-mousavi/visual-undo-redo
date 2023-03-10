#ifndef DELETETARGET_H
#define DELETETARGET_H

#include "action.h"
#include "onode.h"
#include <QVector>

class DeleteTarget : public Action
{
public:
    DeleteTarget(ONode * node);
    ~DeleteTarget();
    void undo();
    void redo();
    void checkNodes(QVector <ONode *>);
    ONode *classNode;
    QVector<ONode *> tempOfTargetNodes;
    bool visibilityOff;
    bool visibilityOn;
};

#endif // DELETETARGET_H
