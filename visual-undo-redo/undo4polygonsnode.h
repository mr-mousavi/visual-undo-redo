#ifndef UNDO4POLYGONSNODE_H
#define UNDO4POLYGONSNODE_H

#include "action.h"
#include "onode.h"

class Undo4PolygonsNode : public Action
{
public:
    Undo4PolygonsNode(ONode *node);
    ~Undo4PolygonsNode();

    void undo();
    void redo();
private:
    ONode *classPolygonNode;
    bool visibilityOff;
    bool visibilityOn;
};

#endif // UNDO4POLYGONSNODE_H
