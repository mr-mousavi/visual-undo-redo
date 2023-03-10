#ifndef UNDO4PROPERTYRET_H
#define UNDO4PROPERTYRET_H

#include "action.h"
#include "orectangle.h"

class Undo4PropertyRect : public Action
{
public:
    Undo4PropertyRect(ORectAngle * rect);
    void undo();
    void redo();
    void firstRect(int a,int b,int c,int d);
    void secondRect(int a, int b, int c, int d);

private:
    ORectAngle *classRect;
    bool visibilityOff;
    bool visibilityOn;
    int x,y,w,h;
    int x1,y1,w1,h1;
};

#endif // UNDO4PROPERTYRET_H
