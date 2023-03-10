#ifndef UNDO4PROPERTYCIRCLE_H
#define UNDO4PROPERTYCIRCLE_H
#include "action.h"
#include "ocircle.h"

class Undo4PropertyCircle : public Action
{
public:
    Undo4PropertyCircle(OCircle * circle);
    ~Undo4PropertyCircle();
    void undo();
    void redo();
    void firstCircle(int a,int b,int c);
    void secondCircle(int a,int b,int c);
private:
    OCircle * classCircle;
    bool visibilityOff;
    bool visibilityOn;
    int x,y,r;
    int x1,y1,r1;
};

#endif // UNDO4PROPERTYCIRCLE_H
