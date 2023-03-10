#ifndef UNDO4DELETERECT_H
#define UNDO4DELETERECT_H

#include "action.h"
#include "orectangle.h"

class Undo4DeleteRect : public Action
{
public:
    Undo4DeleteRect(ORectAngle *rect);
    ~Undo4DeleteRect();
    void undo();
    void redo();

private:
    ORectAngle *classRect;
    bool visibilityOff;
    bool visibilityOn;
};

#endif // UNDO4DELETERECT_H
