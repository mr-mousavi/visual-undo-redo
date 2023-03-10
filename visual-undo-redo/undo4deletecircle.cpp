#include "undo4deletecircle.h"

Undo4DeleteCircle::Undo4DeleteCircle(OCircle * circle)
{
    classCircle=new OCircle();
    classCircle=circle;
    visibilityOff=false;
    visibilityOn=true;
}
Undo4DeleteCircle::~Undo4DeleteCircle()
{
    delete classCircle;
}
//************************************************************
void Undo4DeleteCircle::undo()
{
    if(classCircle->visibility==false)
        classCircle->visibility=visibilityOn;
    else
        classCircle->visibility=visibilityOff;
    classCircle->setVisible(true);
}
//************************************************************
void Undo4DeleteCircle::redo()
{
    if(classCircle->visibility==true)
        classCircle->visibility=visibilityOff;
    else
        classCircle->visibility=visibilityOn;
    classCircle->setVisible(false);

}
//************************************************************
