#ifndef UNDO4DELETECIRCLE_H
#define UNDO4DELETECIRCLE_H

#include "action.h"
#include "ocircle.h"

class Undo4DeleteCircle : public Action
{
public:
    Undo4DeleteCircle(OCircle * circle);
    ~Undo4DeleteCircle();
    void undo();
    void redo();

private:
    OCircle *classCircle;
    bool visibilityOff;
    bool visibilityOn;
};

#endif // UNDO4DELETECIRCLE_H
