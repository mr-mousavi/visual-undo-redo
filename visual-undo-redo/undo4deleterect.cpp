#include "undo4deleterect.h"

Undo4DeleteRect::Undo4DeleteRect(ORectAngle *rect)
{
    classRect=new ORectAngle();
    classRect=rect;
    visibilityOff=false;
    visibilityOn=true;
}
Undo4DeleteRect::~Undo4DeleteRect()
{
    delete classRect;
}
//************************************************************
void Undo4DeleteRect::undo()
{
    if(classRect->visibility==false)
        classRect->visibility=visibilityOn;
    else
        classRect->visibility=visibilityOff;
    classRect->setVisible(true);
}
//************************************************************
void Undo4DeleteRect::redo()
{
    if(classRect->visibility==true)
        classRect->visibility=visibilityOff;
    else
        classRect->visibility=visibilityOn;
    classRect->setVisible(false);

}
