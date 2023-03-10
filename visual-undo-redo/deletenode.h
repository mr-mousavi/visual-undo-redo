#ifndef DELETENODE_H
#define DELETENODE_H

#include "action.h"
#include "onode.h"

class DeleteNode : public Action
{
public:
    DeleteNode(ONode *node);
    ~DeleteNode();
    void undo();
    void redo();
private:
    ONode *classNode;
    bool visibilityOff;
    bool visibilityOn;
};

#endif // DELETENODE_H
