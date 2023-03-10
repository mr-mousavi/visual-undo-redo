#ifndef ACTION_H
#define ACTION_H

class Action              //this class is parent of ChangingProperty class and DeleteNode class and DeleteTarget class.
{
public:
    Action();
    virtual ~Action();
    virtual void undo()=0;
    virtual void redo()=0;

private:

};

#endif // ACTION_H
