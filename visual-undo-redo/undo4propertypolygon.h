#ifndef UNDO4PROPERTYPOLYGON_H
#define UNDO4PROPERTYPOLYGON_H

#include "action.h"
#include "opolygon.h"

class Undo4PropertyPolygon : public Action
{
public:
    Undo4PropertyPolygon(ONode * node);
    ~Undo4PropertyPolygon();

    void undo();
    void redo();

    ONode * classPolygonNodes;
    void firstNode(int a,int b);
    void secondNode(int a,int b);
private:
    int x;
    int y;
    int x2;
    int y2;
};

#endif // UNDO4PROPERTYPOLYGON_H
