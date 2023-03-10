#include "undo4propertycircle.h"

Undo4PropertyCircle::Undo4PropertyCircle(OCircle * circle)
{
    classCircle=new OCircle();
    classCircle=circle;
    visibilityOff=false;
    visibilityOn=true;
}
Undo4PropertyCircle::~Undo4PropertyCircle()
{
    delete classCircle;
}

void Undo4PropertyCircle::undo()
{
    classCircle->center.setX(x);
    classCircle->center.setY(y);
    classCircle->radius=r;

    classCircle->setGeometry(classCircle->center.x()-(this->r/2),
                                  classCircle->center.y()-(this->r/2),
                                  this->r,
                                  this->r);
}

void Undo4PropertyCircle::redo()
{
    classCircle->center.setX(x1);
    classCircle->center.setY(y1);
    classCircle->radius=r1;

    classCircle->setGeometry(classCircle->center.x()-(this->r/2),
                                  classCircle->center.y()-(this->r/2),
                                  this->r,
                                  this->r);
}

void Undo4PropertyCircle::firstCircle(int a, int b, int c)
{
    x=a;
    y=b;
    r=c;
}

void Undo4PropertyCircle::secondCircle(int a, int b, int c)
{
    x1=a;
    y1=b;
    r1=c;
}
