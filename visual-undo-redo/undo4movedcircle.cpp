#include "undo4movedcircle.h"

Undo4MovedCircle::Undo4MovedCircle(OCircle * circle)
{
    classCircle=new OCircle();
    classCircle=circle;

}
Undo4MovedCircle::~Undo4MovedCircle()
{
    delete classCircle;
}
//************************************************************
void Undo4MovedCircle::undo()
{
    classCircle->center.setX(x);
    classCircle->center.setY(y);
    classCircle->radius=r;
    classCircle->setGeometry(classCircle->center.x()-(classCircle->radius/2),
                             classCircle->center.y()-(classCircle->radius/2),
                             classCircle->radius,classCircle->radius);
    classCircle->setVisible(true);

}
//************************************************************
void Undo4MovedCircle::redo()
{
    classCircle->center.setX(x2);
    classCircle->center.setY(y2);
    classCircle->radius=r2;
    classCircle->setGeometry(classCircle->center.x()-(classCircle->radius/2),
                             classCircle->center.y()-(classCircle->radius/2),
                             classCircle->radius,classCircle->radius);
    classCircle->setVisible(true);

}
//************************************************************
void Undo4MovedCircle::beforeMoved(int a,int b,int c)
{
    x=a;
    y=b;
    r=c;
}
//************************************************************
void Undo4MovedCircle::afterMoved(int a,int b,int c)
{
    x2=a;
    y2=b;
    r2=c;
}
