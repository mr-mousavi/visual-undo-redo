#ifndef UNDO4MOVEDCIRCLE_H
#define UNDO4MOVEDCIRCLE_H

#include "action.h"
#include "ocircle.h"

class Undo4MovedCircle : public Action
{
public:
    Undo4MovedCircle(OCircle * circle);
    ~Undo4MovedCircle();
    void undo();
    void redo();
    void beforeMoved(int a,int b,int c);
    void afterMoved(int a,int b,int c);

private:
    OCircle *classCircle;
    int x,y,r;
    int x2,y2,r2;

};

#endif // UNDO4MOVEDCIRCLE_H
