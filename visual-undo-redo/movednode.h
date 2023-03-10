#ifndef MOVEDNODE_H
#define MOVEDNODE_H

#include "action.h"
#include "onode.h"


class movedNode  : public Action
{
public:
    movedNode(ONode * node);
    void undo();
    void redo();
    void beforeMoved(int x,int y);
    void afterMoved(int x,int y);

private:
    ONode *classNode;
    int x1;
    int y1;
    int x2;
    int y2;

};

#endif // MOVEDNODE_H
