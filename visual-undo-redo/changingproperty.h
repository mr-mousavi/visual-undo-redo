#ifndef CHANGINGPROPERTY_H
#define CHANGINGPROPERTY_H

#include "action.h"
#include "otarget.h"

class ChangingProperty : public Action
{
public:
    ChangingProperty(ONode * node);
    ~ChangingProperty();
    void undo();
    void redo();
    ONode * classNode;
    void firstNode(int a,int b,int c);
    void secondNode(int a,int b,int c);
private:
    int x;
    int y;
    int s;
    int x2;
    int y2;
    int s2;
};

#endif // CHANGINGPROPERTY_H
