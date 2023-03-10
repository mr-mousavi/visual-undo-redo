#include "undo4movedrectangle.h"

Undo4MovedRectangle::Undo4MovedRectangle(ORectAngle * rect)
{
    classRect=new ORectAngle();
    classRect=rect;
}
Undo4MovedRectangle::~Undo4MovedRectangle()
{
    delete classRect;
}

void Undo4MovedRectangle::undo()
{
    classRect->firstPoint.setX(x);
    classRect->firstPoint.setY(y);
    classRect->secondPoint.setX(w);
    classRect->secondPoint.setY(h);

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
    classRect->setVisible(true);

}

void Undo4MovedRectangle::redo()
{
    classRect->firstPoint.setX(x2);
    classRect->firstPoint.setY(y2);
    classRect->secondPoint.setX(w2);
    classRect->secondPoint.setY(h2);

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
    classRect->setVisible(true);

}

void Undo4MovedRectangle::beforeMoved(int a,int b,int c,int d)
{
    x=a;
    y=b;
    w=c;
    h=d;
}

void Undo4MovedRectangle::afterMoved(int a,int b,int c,int d)
{
    x2=a;
    y2=b;
    w2=c;
    h2=d;
}
