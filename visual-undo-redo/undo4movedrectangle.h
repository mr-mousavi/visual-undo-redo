#ifndef UNDO4MOVEDRECTANGLE_H
#define UNDO4MOVEDRECTANGLE_H

#include "action.h"
#include "orectangle.h"

class Undo4MovedRectangle : public Action
{
public:
    Undo4MovedRectangle(ORectAngle * rect);
    ~Undo4MovedRectangle();
    void undo();
    void redo();
    void beforeMoved(int a,int b,int c,int d);
    void afterMoved(int a,int b,int c,int d);

private:
    ORectAngle *classRect;
    int x,y,w,h;
    int x2,y2,w2,h2;
};

#endif // UNDO4MOVEDRECTANGLE_H
