#include "undo4propertyrect.h"

Undo4PropertyRect::Undo4PropertyRect(ORectAngle * rect)
{
    classRect=new ORectAngle();
    classRect=rect;
    visibilityOff=false;
    visibilityOn=true;
}
void Undo4PropertyRect::undo()
{
    classRect->firstPoint.setX(x);
    classRect->firstPoint.setY(y);


        if(classRect->firstPoint.x()<classRect->secondPoint.x()  &&  classRect->firstPoint.y() <classRect->secondPoint.y())   //top left to bottom right
        {
            classRect->secondPoint.setX(classRect->firstPoint.x() + this->w);
            classRect->secondPoint.setY(classRect->firstPoint.y() + this->h);
        }

        if(classRect->firstPoint.x()>classRect->secondPoint.x()  &&  classRect->firstPoint.y() < classRect->secondPoint.y())  //top right to bottom left
        {
             classRect->secondPoint.setX(classRect->firstPoint.x() - this->w);
             classRect->secondPoint.setY(classRect->firstPoint.y() + this->h);
        }

        if(classRect->firstPoint.x()>classRect->secondPoint.x() && classRect->firstPoint.y() >classRect->secondPoint.y())    //bottom right to top left
        {
            classRect->secondPoint.setX(classRect->firstPoint.x() - this->w);
            classRect->secondPoint.setY(classRect->firstPoint.y() - this->h);
        }

        if(classRect->firstPoint.x()<classRect->secondPoint.x() && classRect->firstPoint.y() >classRect->secondPoint.y())    //bottom left to top right
        {
            classRect->secondPoint.setX(classRect->firstPoint.x() + this->w);
            classRect->secondPoint.setY(classRect->firstPoint.y() - this->h);
        }

        //set geometry for undo
        if(classRect->firstPoint.x()<classRect->secondPoint.x()  &&  classRect->firstPoint.y() <classRect->secondPoint.y())   //top left to bottom right
        {
            classRect->setGeometry(classRect->firstPoint.x(),
                            classRect->firstPoint.y(),
                            classRect->secondPoint.x()-classRect->firstPoint.x(),
                            classRect->secondPoint.y()-classRect->firstPoint.y());
        }
        if(classRect->firstPoint.x()>classRect->secondPoint.x()  &&  classRect->firstPoint.y() < classRect->secondPoint.y())  //top right to bottom left
        {
            classRect->setGeometry(classRect->secondPoint.x(),
                              classRect->firstPoint.y(),
                              classRect->firstPoint.x()-classRect->secondPoint.x(),
                              classRect->secondPoint.y()-classRect->firstPoint.y());
        }
        if(classRect->firstPoint.x()>classRect->secondPoint.x() && classRect->firstPoint.y() >classRect->secondPoint.y())    //bottom right to top left
        {
            classRect->setGeometry(classRect->secondPoint.x(),
                              classRect->secondPoint.y(),
                              classRect->firstPoint.x()-classRect->secondPoint.x(),
                              classRect->firstPoint.y()-classRect->secondPoint.y());
        }
        if(classRect->firstPoint.x()<classRect->secondPoint.x() && classRect->firstPoint.y() >classRect->secondPoint.y())    //bottom left to top right
        {
            classRect->setGeometry(classRect->firstPoint.x(),
                              classRect->secondPoint.y(),
                              classRect->secondPoint.x()-classRect->firstPoint.x(),
                              classRect->firstPoint.y()-classRect->secondPoint.y());
        }


}

void Undo4PropertyRect::redo()
{
    classRect->firstPoint.setX(x1);
    classRect->firstPoint.setY(y1);

    if(classRect->firstPoint.x()<classRect->secondPoint.x()  &&  classRect->firstPoint.y() <classRect->secondPoint.y())   //top left to bottom right
    {
        classRect->secondPoint.setX(classRect->firstPoint.x() + this->w1);
        classRect->secondPoint.setY(classRect->firstPoint.y() + this->h1);
    }

    if(classRect->firstPoint.x()>classRect->secondPoint.x()  &&  classRect->firstPoint.y() < classRect->secondPoint.y())  //top right to bottom left
    {
         classRect->secondPoint.setX(classRect->firstPoint.x() - this->w1);
         classRect->secondPoint.setY(classRect->firstPoint.y() + this->h1);
    }

    if(classRect->firstPoint.x()>classRect->secondPoint.x() && classRect->firstPoint.y() >classRect->secondPoint.y())    //bottom right to top left
    {
        classRect->secondPoint.setX(classRect->firstPoint.x() - this->w1);
        classRect->secondPoint.setY(classRect->firstPoint.y() - this->h1);
    }

    if(classRect->firstPoint.x()<classRect->secondPoint.x() && classRect->firstPoint.y() >classRect->secondPoint.y())    //bottom left to top right
    {
        classRect->secondPoint.setX(classRect->firstPoint.x() + this->w1);
        classRect->secondPoint.setY(classRect->firstPoint.y() - this->h1);
    }

    //set geometry for redo
    if(classRect->firstPoint.x()<classRect->secondPoint.x()  &&  classRect->firstPoint.y() <classRect->secondPoint.y())   //top left to bottom right
    {
        classRect->setGeometry(classRect->firstPoint.x(),
                        classRect->firstPoint.y(),
                        classRect->secondPoint.x()-classRect->firstPoint.x(),
                        classRect->secondPoint.y()-classRect->firstPoint.y());
    }
    if(classRect->firstPoint.x()>classRect->secondPoint.x()  &&  classRect->firstPoint.y() < classRect->secondPoint.y())  //top right to bottom left
    {
        classRect->setGeometry(classRect->secondPoint.x(),
                          classRect->firstPoint.y(),
                          classRect->firstPoint.x()-classRect->secondPoint.x(),
                          classRect->secondPoint.y()-classRect->firstPoint.y());
    }
    if(classRect->firstPoint.x()>classRect->secondPoint.x() && classRect->firstPoint.y() >classRect->secondPoint.y())    //bottom right to top left
    {
        classRect->setGeometry(classRect->secondPoint.x(),
                          classRect->secondPoint.y(),
                          classRect->firstPoint.x()-classRect->secondPoint.x(),
                          classRect->firstPoint.y()-classRect->secondPoint.y());
    }
    if(classRect->firstPoint.x()<classRect->secondPoint.x() && classRect->firstPoint.y() >classRect->secondPoint.y())    //bottom left to top right
    {
        classRect->setGeometry(classRect->firstPoint.x(),
                          classRect->secondPoint.y(),
                          classRect->secondPoint.x()-classRect->firstPoint.x(),
                          classRect->firstPoint.y()-classRect->secondPoint.y());
    }
}

void Undo4PropertyRect::firstRect(int a, int b, int c, int d)
{
    x=a;
    y=b;
    w=c;
    h=d;
}

void Undo4PropertyRect::secondRect(int a, int b, int c, int d)
{
    x1=a;
    y1=b;
    w1=c;
    h1=d;
}
