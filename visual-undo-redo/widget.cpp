#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    LastId=0;
    r=0;
    flag=false;
    flag4Rectangle=false;
    flag4Circle=false;
    flag4Polygon=false;
    flag4ControlPolygon=false;

    setMouseTracking(true);

    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage( "D:\\documents\\iranian-autopia-doc\\site info\\iran-full-size.jpg")));
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    QHBoxLayout *hbox1 = new QHBoxLayout(this);
    QHBoxLayout *hbox2 = new QHBoxLayout (this);
    QPushButton *runButton=new QPushButton(tr("&Run"));
    QPushButton *saveButton=new QPushButton(tr("&Save"));
    QPushButton *loadButton=new QPushButton(tr("&Load"));
    QPushButton *undoButton=new QPushButton(tr("Undo"));
    QPushButton *redoButton=new QPushButton(tr("Redo"));
    QPushButton *addPath=new QPushButton(tr("AddPath"));
    QPushButton *drawCircle=new QPushButton(tr("DrawCircle"));
    QPushButton *drawRectangle=new QPushButton(tr("DrawRectangle"));
    QPushButton *polygon=new QPushButton(tr("DrawPlygon"));

    hbox1->setSpacing(3);
    hbox1->addStretch(1);
    hbox1->addWidget(runButton,0,Qt::AlignTop);
    hbox1->addWidget(saveButton,0,Qt::AlignTop);
    hbox1->addWidget(loadButton,0,Qt::AlignTop);
    hbox1->addWidget(undoButton,0,Qt::AlignTop);
    hbox1->addWidget(redoButton,0,Qt::AlignTop);
    hbox1->addWidget(addPath,0,Qt::AlignTop);
    hbox1->addWidget(drawCircle,0,Qt::AlignTop);
    hbox1->addWidget(drawRectangle,0,Qt::AlignTop);
    hbox1->addWidget(polygon,0,Qt::AlignTop);
    hbox1->addStretch(1);

    hbox2->addSpacing(10);
    hbox2->addLayout(hbox1);
    setLayout(hbox2);

    connect(addPath,SIGNAL(clicked()),this,SLOT(addPath()));
    connect(undoButton,SIGNAL(clicked()),this,SLOT(undoSlot()));
    connect(redoButton,SIGNAL(clicked()),this,SLOT(redoSlot()));
    connect(saveButton,SIGNAL(clicked()),this,SLOT(saveWindow()));
    connect(loadButton,SIGNAL(clicked()),this,SLOT(loadWindow()));
    connect(drawCircle,SIGNAL(clicked()),this,SLOT(drawCircle()));
    connect(drawRectangle,SIGNAL(clicked()),this,SLOT(drawRectangle()));
    connect(polygon,SIGNAL(clicked()),this,SLOT(drawPolygon()));

}
Widget::~Widget() //destructor
{
}
//*********************************************************
void Widget::mousePressEvent(QMouseEvent *event)
{
    int size=undoList.size();
         if(whichShape==0 || whichShape==1 || whichShape==2 || whichShape==3)
         {
             redoList.clear();
             for (int i=0;i<redoList.size();i++)
             {
                 delete redoList.back();
             }
         }

        if(flag==false && whichShape==0)
        {
            points=new OTarget();
            points->Id=generateId();
            allCoordinate.append(points);
            flag=true;
            flag4Click=false;
        }

        if(flag4Click==false && whichShape==0)
        {
            thisPoint=new ONode(this);
        if(event->buttons() == Qt::LeftButton)
        {
            thisPoint->point=new QPoint(event->pos());
            thisPoint->setSpeed(points->speed);
            thisPoint->setGeometry(thisPoint->point->x()-5,thisPoint->point->y()-5,10,10);
            thisPoint->whichOne=targetAction;
             points->coordinate.append(thisPoint);

        objNode=new DeleteNode(thisPoint);
        undoList.append(objNode);
        }

        if (event->buttons() == Qt::RightButton)
        {
            thisPoint->point=new QPoint(event->pos());
            thisPoint->setSpeed(points->speed);
            thisPoint->setGeometry(thisPoint->point->x()-5,thisPoint->point->y()-5,10,10);
            thisPoint->whichOne=targetAction;
            points->coordinate.append(thisPoint);

            objNode=new DeleteNode(thisPoint);
            undoList.append(objNode);
            flag4Click=true;
            whichShape=nothing;

        }
        thisPoint->setVisible(true);
        connect(thisPoint,SIGNAL(signalDeleteNodeFunc(ONode *)),this,SLOT(nodeSetting(ONode *)));
        connect(thisPoint,SIGNAL(signalDeleteTargetFunc(ONode*)),this,SLOT(targetSetting(ONode *)));
        connect(thisPoint,SIGNAL(signalPropertiesTarget(ONode*)),this,SLOT(property(ONode *)));
        connect(thisPoint,SIGNAL(signalDrawLines(ONode *)),this,SLOT(drawAgain(ONode *)));
        connect(thisPoint,SIGNAL(signalUpdate()),this,SLOT(slotUpdate()));
        }

        //draw circle
        if(whichShape==1 && flag4Circle==true)
        {
            if(event->buttons() && Qt::LeftButton)
            {
                circle=new OCircle(this);
                circle->Id=generateId4Circle();
                circleCenter=circle->center=event->pos();
            }
            connect(circle,SIGNAL(signalDeleteCircle(OCircle*)),this,SLOT(circleSetting(OCircle*)));
            connect(circle,SIGNAL(signalPropertyCircle(OCircle*)),this,SLOT(propertyCircle(OCircle*)));
            connect(circle,SIGNAL(signalDrawAgainCircle(OCircle*)),this,SLOT(drawAgainCircle(OCircle*)));
            connect(circle,SIGNAL(signalUpdateCircle()),this,SLOT(slotUpdateCircle()));
        }

        //draw rectangle
        if(whichShape==2 && flag4Rectangle==true)
        {
            if(event->buttons() && Qt::LeftButton)
            {
                rect=new ORectAngle(this);
                rect->Id=generateId4Rect();
                rect->firstPoint=(event->pos());
            }
            connect(rect,SIGNAL(signalDeleteRectangle(ORectAngle*)),this,SLOT(rectangleSetting(ORectAngle*)));
            connect(rect,SIGNAL(signalPropertiesRectangle(ORectAngle*)),this,SLOT(propertyRectangle(ORectAngle*)));
            connect(rect,SIGNAL(signalDrawAgainRectangle(ORectAngle*)),this,SLOT(drawAgainRectngle(ORectAngle*)));
            connect(rect,SIGNAL(signalUpdateRecangle()),this,SLOT(slotUpdateRectangl()));
        }

        //draw polygon
        if(flag4ControlPolygon==true && whichShape==3)
        {
            polygon=new OPolygon(this);
            polygon->Id=generateId4Polygon();
            allPolygon.append(polygon);
            flag4ControlPolygon=false;
            flag4Polygon=true;
        }
        if(whichShape==3 && flag4Polygon==true )
        {
            polyNode=new ONode(this);
            if(event->buttons() == Qt::LeftButton)
            {
                polyNode->point=new QPoint(event->pos());
                polyNode->setGeometry(polyNode->point->x()-5,polyNode->point->y()-5,10,10);
                polyNode->whichOne=polygonAction;
                polygon->onePoly.append(polyNode);

                    objPolygonNode=new Undo4PolygonsNode(polyNode);
                    undoList.append(objPolygonNode);
            }

            if(event->buttons() == Qt::RightButton)
            {
                polygon->setIsClosed(true);
                polyNode->point=new QPoint(event->pos());
                polyNode->setGeometry(polyNode->point->x()-5,polyNode->point->y()-5,10,10);
                polyNode->whichOne=polygonAction;
                polygon->onePoly.append(polyNode);

                flag4Polygon=false;
                    objPolygonNode=new Undo4PolygonsNode(polyNode);
                    undoList.append(objPolygonNode);
                    whichShape=nothing;
            }
            polyNode->setVisible(true);
            connect(polyNode,SIGNAL(signalDeletePolygonNodeFunc(ONode*)),this,SLOT(polygonNodeSetting(ONode *)));
            connect(polyNode,SIGNAL(signalDeletePolygonFunc(ONode *)),this,SLOT(polygonSetting(ONode *)));
            connect(polyNode,SIGNAL(signalPropertyPolygon(ONode*)),this,SLOT(propertyPolygon(ONode *)));
            connect(polyNode,SIGNAL(signalDrawLines(ONode *)),this,SLOT(drawAgain(ONode *)));
            connect(polyNode,SIGNAL(signalUpdate()),this,SLOT(slotUpdate()));

        }
update();
}
//************************************************************
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() == Qt::LeftButton && whichShape==1 && flag4Circle==true)
    {
        qint32 x=((cursor().pos().x())-(circle->center.x()));
        qint32 y=((cursor().pos().y())-(circle->center.y()));
        r=sqrt((x*x)+(y*y));
    }

    if(event->buttons() == Qt::LeftButton && whichShape==2 && flag4Rectangle==true)
    {
        xRect=rect->firstPoint.x();
        yRect=rect->firstPoint.y();
        wRect=cursor().pos().x()-rect->firstPoint.x();
        hRect=cursor().pos().y()-rect->firstPoint.y();
    }
    update();
}
//************************************************************
void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(whichShape==1 && flag4Circle==true)
    {

       circle->radius=r;
       circle->setGeometry(circle->center.x()-(r/2),circle->center.y()-(r/2),r,r);

       circle->setVisible(true);
       allCircle.append(circle);
       flag4Circle=false;
           objCircle=new Undo4DeleteCircle(circle);
           undoList.append(objCircle);
           whichShape=nothing;
       r=0;
    }

    if(whichShape==2 && flag4Rectangle==true)
    {
    rect->secondPoint=(cursor().pos());

    if(rect->firstPoint.x()<rect->secondPoint.x()  &&  rect->firstPoint.y() <rect->secondPoint.y())   //top left to bottom right
    {
        rect->setGeometry(rect->firstPoint.x(),
                        rect->firstPoint.y(),
                        rect->secondPoint.x()-rect->firstPoint.x(),
                        rect->secondPoint.y()-rect->firstPoint.y());
    }
    if(rect->firstPoint.x()>rect->secondPoint.x()  &&  rect->firstPoint.y() < rect->secondPoint.y())  //top right to bottom left
    {
        rect->setGeometry(rect->secondPoint.x(),
                          rect->firstPoint.y(),
                          rect->firstPoint.x()-rect->secondPoint.x(),
                          rect->secondPoint.y()-rect->firstPoint.y());
    }
    if(rect->firstPoint.x()>rect->secondPoint.x() && rect->firstPoint.y() >rect->secondPoint.y())    //bottom right to top left
    {
        rect->setGeometry(rect->secondPoint.x(),
                          rect->secondPoint.y(),
                          rect->firstPoint.x()-rect->secondPoint.x(),
                          rect->firstPoint.y()-rect->secondPoint.y());
    }
    if(rect->firstPoint.x()<rect->secondPoint.x() && rect->firstPoint.y() >rect->secondPoint.y())    //bottom left to top right
    {
        rect->setGeometry(rect->firstPoint.x(),
                          rect->secondPoint.y(),
                          rect->secondPoint.x()-rect->firstPoint.x(),
                          rect->firstPoint.y()-rect->secondPoint.y());
    }

    rect->setVisible(true);
    allRectangle.append(rect);
    flag4Rectangle=false;

    objRect=new Undo4DeleteRect(rect);
    undoList.append(objRect);
    whichShape=nothing;
    xRect=yRect=wRect=hRect=0;


    }
}
//***********************************************************
void Widget::drawLines(QPainter *l)
{
    for(int m=0;m< allCoordinate.size();m++)
    {
    tempLinePoint.clear();
        for(int mm=0;mm<allCoordinate.at(m)->coordinate.size();mm++)
        {

            if(allCoordinate.at(m)->coordinate.at(mm)->visibility==true)
                {
                tempLinePoint.append(*allCoordinate.at(m)->coordinate.at(mm)->point);     //  tempLine=allCoordinate[m];   we can not acces to vector with OTarget type with [] operator
                allCoordinate.at(m)->coordinate.at(mm)->drawEllipse(l);   // call function drawEllipse for drawing ellipse in ONode class
                }
        }

    l->drawLines(tempLinePoint);
    tempLine2Point=tempLinePoint;

    // for drawing line because drawlines with vector-> Draws a line for each pair of points in the vector

        if (!tempLine2Point.empty())
        {
           tempLine2Point.pop_front();
                for(int q=0;q<tempLine2Point.size();q++)
                {
                   l->drawLines(tempLine2Point);
                }
        }
    }
}
//************************************************************
void Widget::drawRectAngles(QPainter *l)
{
    for(int i=0;i<allRectangle.size();i++)
    {
        if(allRectangle.at(i)->visibility==true)
        {
        allRectangle.at(i)->drawRectangle(l);
        }
    }
}
//************************************************************
void Widget::drawCircles(QPainter *l)
{
    for(int i=0;i<allCircle.size();i++)
    {
        if(allCircle.at(i)->visibility==true)
        {
        allCircle.at(i)->drawCircle(l);
        }
    }
}
//************************************************************
void Widget::drawPolygons(QPainter *l)
{
    QVector<QPoint> onePolyTemp;
    QVector<QPoint> onePolyTemp2;

    for(int m=0;m< allPolygon.size();m++)
    {
    onePolyTemp.clear();
        for(int mm=0;mm<allPolygon.at(m)->onePoly.size();mm++)
        {
            if(allPolygon.at(m)->visibility==true)
                {
                    if(allPolygon.at(m)->onePoly.at(mm)->visibility==true)
                        {
                    onePolyTemp.append(*allPolygon.at(m)->onePoly.at(mm)->point);
                    allPolygon.at(m)->onePoly.at(mm)->drawEllipse(l);
                        }
                }
        }

        //for closing polygon
        if(allPolygon.at(m)->isClosed())
        {
            int h=0;
            for(int n=0;n< allPolygon.size();n++)
            {
                for(int nn=0;nn<allPolygon.at(n)->onePoly.size();nn++)
                {

//                    l->drawLine(*allPolygon.at(m)->onePoly.at(allPolygon.at(m)->onePoly.size()-1)->point,
//                                *allPolygon.at(m)->onePoly.at(0)->point);
                    if(allPolygon.at(m)->visibility==false)
                    {
                        h++;
                    }
                        if(!onePolyTemp.empty())
                        {
                        l->drawLine(onePolyTemp.at(onePolyTemp.size()-1),onePolyTemp.at(h));
                        }

                }
            }
        }
        //drawLinse
                l->drawLines(onePolyTemp);
                onePolyTemp2=onePolyTemp;

                if(!onePolyTemp2.empty())
                {
                    onePolyTemp2.pop_front();
                    for(int i=0;i<onePolyTemp2.size();i++)
                    {
                        l->drawLines(onePolyTemp2);
                    }
                }
    }
}
//************************************************************
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter l(this);
    QPen pen(Qt::black, 2, Qt::SolidLine);
    l.setPen(pen);

//    QPainter p(this);
    l.setRenderHint(QPainter::Antialiasing, true);
    l.setBrush(QBrush(Qt::blue, Qt::SolidPattern));

    drawLines(&l);


        //draw circle     //PainterPaths  for fill
        if(whichShape==1 && flag4Circle==true )
        {
            //for filling circle
            QLinearGradient myGradient;
            QPainterPath myPath;
            l.setPen(pen);
            l.drawPath(myPath);
            l.drawEllipse(circleCenter,r,r);
        }
        drawCircles(&l);

                //draw RecAangle
                if(whichShape==2 && flag4Rectangle==true)
                    {
                            l.drawRect(xRect,yRect,wRect,hRect);
                    }

                drawRectAngles(&l);

    drawPolygons(&l);
}
//************************slots********************************
void Widget::undoSlot()
{
        if(!undoList.empty())
        {
            undoList.at((undoList.size()-1))->undo();
            redoList.append(undoList.back());
            undoList.pop_back();
        }
    update();
}
//*************************************************************
void Widget::redoSlot()
{ 
        if(!redoList.empty())
        {
            redoList.at((redoList.size()-1))->redo();

            undoList.append(redoList.back());
            redoList.pop_back();
        }
    update();
}
//*************************************************************
void Widget::nodeSetting(ONode * node)   //this slot is for deleteing(visibility=false) node
{
    node->visibility=false;
    objNode=new DeleteNode(node);
    undoList.append(objNode);
    node->setVisible(false);
    update();
}
//*************************************************************
void Widget::targetSetting(ONode *node)  // this slot is for deleteing(visibility=false) target
{
    //undo
    DeleteTarget * objTarget;
    objTarget=new DeleteTarget(node);
    undoList.append(objTarget);
    //undo
    int first;
    for(int i=0;i<allCoordinate.size();i++)
        {
            for(int j=0;j<allCoordinate.at(i)->coordinate.size();j++)
            {
                if (node == allCoordinate.at(i)->coordinate.at(j))
                {
                    objTarget->checkNodes(allCoordinate.at(i)->coordinate);
                    first=0;
                    while(first!=(allCoordinate.at(i)->coordinate.size()))
                        {
                            allCoordinate.at(i)->coordinate.at(first)->visibility=false;
                            allCoordinate.at(i)->coordinate.at(first)->setVisible(false);
                            first++;
                        }
                }
            }
        }
    update();
}
//************************************************************
void Widget::property(ONode *properties)  //this slot is for changing properties of nodes with right click action
{
    ChangingProperty *objChange;
//undo
    int a=properties->point->x();
    int b=properties->point->y();
    int c=properties->speed;
    objChange=new ChangingProperty(properties);
    objChange->firstNode(a,b,c);
    undoList.append(objChange);
//undo
   properties->getPop->showInfo(properties->point->x(),properties->point->y(),properties->speed);

    properties->x_temp=properties->point->x();
    properties->y_temp=properties->point->y();
    properties->v_temp=properties->speed;

   if(properties->getPop->exec()==QDialog::Accepted)
    {
        properties->getPop->changed();
       if(properties->x_temp!=properties->getPop->x_number)
       {
           properties->point->setX(properties->getPop->x_number);
       }
       if (properties->y_temp!=properties->getPop->y_number)
       {
           properties->point->setY(properties->getPop->y_number);
       }
       if(properties->v_temp!=properties->getPop->v_number)
       {
           for(int i=0;i<allCoordinate.size();i++)
           {
               for(int j=0;j<allCoordinate.at(i)->coordinate.size();j++)
               {
                   if(allCoordinate.at(i)->coordinate.contains(properties))
                   {
                       allCoordinate.at(i)->coordinate.at(j)->speed=properties->getPop->v_number;
                   }
               }
           }
       }
        //undo
       a=properties->point->x();
       b=properties->point->y();
       c=properties->speed;
        //undo
    }
    properties->setGeometry(properties->point->x()-5,properties->point->y()-5,10,10);
    //undo
    objChange->secondNode(a,b,c);
    //undo
}
//***********************************************************
void Widget::saveWindow()
{
    OTarget *target;
    OCircle * saveCircle;
    ORectAngle * rectangle;
    OPolygon * savepolygon;
    qint32 countTarget=allCoordinate.size();
    qint32 countCircle=allCircle.size();
    qint32 countRectangle=allRectangle.size();
    qint32 countPolygon=allPolygon.size();

    QString fileName = QFileDialog::getSaveFileName(
            this,
            tr("Save Document"),
            QDir::currentPath(),
            tr("Documents (*.dat)"));

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);

    QDataStream out(&file);
/////////////////////////////////////////////////////////////////////
//save targets
        out <<(qint32) countTarget;
    for(int i=0;i<countTarget;i++)
    {
        target=allCoordinate.at(i);
        out<<target->toByte();
    }

/////////////////////////////////////////////////////////////////////

    int falseCircle=0;
    for(int i=0;i<allCircle.size();i++)
    {
        if(allCircle.at(i)->visibility==false)
        {
            falseCircle++;
        }
    }
//save circles
    out <<(qint32)countCircle-falseCircle;
        for(int i=0;i<allCircle.size();i++)
        {
            saveCircle=allCircle.at(i);
            if(allCircle.at(i)->visibility==true)
            {
            out<<saveCircle->toByte();
            }
        }

/////////////////////////////////////////////////////////////////////

        int falseRectangle=0;
        for(int i=0;i<allRectangle.size();i++)
        {
            if(allRectangle.at(i)->visibility==false)
            {
                falseRectangle++;
            }
        }
//save recangles
    out<<countRectangle-falseRectangle;

    for(int i=0;i<allRectangle.size();i++)
    {
        rectangle=allRectangle.at(i);
        if(allRectangle.at(i)->visibility==true)
        {
        out<<rectangle->toByte();
        }
    }

/////////////////////////////////////////////////////////////////////
//save polygons
    out<<countPolygon;
    for(int i=0;i<allPolygon.size();i++)
    {
        savepolygon=allPolygon.at(i);
        out<<savepolygon->toByte();
    }

//    out<<circle->center.x();
//    out<<circle->center.y();
//    out<<circle->radius;
//    out<<circle->Id;
    file.close();
}
//***********************************************************
void Widget::showAfterLoad()
{
    ONode *node4Path;
    OCircle * cir;
    ORectAngle * rangle;
    ONode * node4poly;
    for(int i=0;i<allCoordinate.size();i++)
    {
        for(int j=0;j<allCoordinate.at(i)->coordinate.size();j++)
        {
                node4Path=allCoordinate.at(i)->coordinate.at(j);
                node4Path->setParent(this);
                node4Path->setGeometry(node4Path->point->x()-5,node4Path->point->y()-5,10,10);
                node4Path->setVisible(true);

                connect(node4Path,SIGNAL(signalDeleteNodeFunc(ONode *)),this,SLOT(nodeSetting(ONode *)));
                connect(node4Path,SIGNAL(signalDeleteTargetFunc(ONode*)),this,SLOT(targetSetting(ONode *)));
                connect(node4Path,SIGNAL(signalPropertiesTarget(ONode*)),this,SLOT(property(ONode *)));
                connect(node4Path,SIGNAL(signalDrawLines(ONode *)),this,SLOT(drawAgain(ONode *)));
                connect(node4Path,SIGNAL(signalUpdate()),this,SLOT(slotUpdate()));
        }
    }
/////////////////////////////////////////////////////////////////////
    for(int i=0;i<allCircle.size();i++)
    {
        cir=allCircle.at(i);
        cir->setParent(this);
        cir->setGeometry(cir->center.x()-((cir->radius)/2),cir->center.y()-((cir->radius)/2),cir->radius,cir->radius);
        cir->setVisible(true);

        connect(cir,SIGNAL(signalDeleteCircle(OCircle*)),this,SLOT(circleSetting(OCircle*)));
        connect(cir,SIGNAL(signalPropertyCircle(OCircle*)),this,SLOT(propertyCircle(OCircle*)));
        connect(cir,SIGNAL(signalDrawAgainCircle(OCircle*)),this,SLOT(drawAgainCircle(OCircle*)));
        connect(cir,SIGNAL(signalUpdateCircle()),this,SLOT(slotUpdateCircle()));
    }
/////////////////////////////////////////////////////////////////////
    for(int i=0;i<allRectangle.size();i++)
    {
        rangle=allRectangle.at(i);
        rangle->setParent(this);

        if(rangle->firstPoint.x()<rangle->secondPoint.x()  &&  rangle->firstPoint.y() <rangle->secondPoint.y())   //top left to bottom right
        {
            rangle->setGeometry(rangle->firstPoint.x(),
                            rangle->firstPoint.y(),
                            rangle->secondPoint.x()-rangle->firstPoint.x(),
                            rangle->secondPoint.y()-rangle->firstPoint.y());
        }
        if(rangle->firstPoint.x()>rangle->secondPoint.x()  &&  rangle->firstPoint.y() < rangle->secondPoint.y())  //top right to bottom left
        {
            rangle->setGeometry(rangle->secondPoint.x(),
                              rangle->firstPoint.y(),
                              rangle->firstPoint.x()-rangle->secondPoint.x(),
                              rangle->secondPoint.y()-rangle->firstPoint.y());
        }
        if(rangle->firstPoint.x()>rangle->secondPoint.x() && rangle->firstPoint.y() >rangle->secondPoint.y())    //bottom right to top left
        {
            rangle->setGeometry(rangle->secondPoint.x(),
                              rangle->secondPoint.y(),
                              rangle->firstPoint.x()-rangle->secondPoint.x(),
                              rangle->firstPoint.y()-rangle->secondPoint.y());
        }
        if(rangle->firstPoint.x()<rangle->secondPoint.x() && rangle->firstPoint.y() >rangle->secondPoint.y())    //bottom left to top right
        {
            rangle->setGeometry(rangle->firstPoint.x(),
                              rangle->secondPoint.y(),
                              rangle->secondPoint.x()-rangle->firstPoint.x(),
                              rangle->firstPoint.y()-rangle->secondPoint.y());
        }
        rangle->setVisible(true);

        connect(rangle,SIGNAL(signalDeleteRectangle(ORectAngle*)),this,SLOT(rectangleSetting(ORectAngle*)));
        connect(rangle,SIGNAL(signalPropertiesRectangle(ORectAngle*)),this,SLOT(propertyRectangle(ORectAngle*)));
        connect(rangle,SIGNAL(signalDrawAgainRectangle(ORectAngle*)),this,SLOT(drawAgainRectngle(ORectAngle*)));
        connect(rangle,SIGNAL(signalUpdateRecangle()),this,SLOT(slotUpdateRectangl()));
    }
/////////////////////////////////////////////////////////////////////
    for(int i=0;i<allPolygon.size();i++)
    {
        for(int j=0;j<allPolygon.at(i)->onePoly.size();j++)
        {
            node4poly=allPolygon.at(i)->onePoly.at(j);
            node4poly->setParent(this);
            node4poly->setGeometry(node4poly->point->x()-5,node4poly->point->y()-5,10,10);
            node4poly->setVisible(true);
            connect(node4poly,SIGNAL(signalDeletePolygonNodeFunc(ONode*)),this,SLOT(polygonNodeSetting(ONode *)));
            connect(node4poly,SIGNAL(signalDeletePolygonFunc(ONode *)),this,SLOT(polygonSetting(ONode *)));
            connect(node4poly,SIGNAL(signalPropertyPolygon(ONode*)),this,SLOT(propertyPolygon(ONode *)));
            connect(node4poly,SIGNAL(signalDrawLines(ONode *)),this,SLOT(drawAgain(ONode *)));
            connect(node4poly,SIGNAL(signalUpdate()),this,SLOT(slotUpdate()));

        }
    }
}
//***********************************************************
void Widget::loadWindow()
{
    qint32 countTarget;
    qint32 countcircle;
    qint32 countRectangle;
    qint32 countPolygon;

    QString fileName=QFileDialog::getOpenFileName(
                this,
                tr("open Document"),
                QDir::currentPath(),
                tr("Documents (*.dat)"));

    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QDataStream * read=new QDataStream(&file);

/////////////////////////////////////////////////////////////////////
//load targets
    *read >> countTarget;              //read  number of target
    for(int i=0;i<countTarget;i++)
    {
        OTarget *target=new OTarget();
        target->fill(read);
        allCoordinate.append(target);
    }

/////////////////////////////////////////////////////////////////////
//load circles
    *read>>countcircle;
    for(int i=0;i<countcircle;i++)
    {
        OCircle *circle=new OCircle();
        circle->fill(read);
        allCircle.append(circle);
    }

/////////////////////////////////////////////////////////////////////
//load rectangles
    *read>>countRectangle;
    for(int i=0;i<countRectangle;i++)
    {
        ORectAngle * rangle=new ORectAngle();
        rangle->fill(read);
        allRectangle.append(rangle);
    }

/////////////////////////////////////////////////////////////////////
//load polygons
    *read>>countPolygon;
    for(int i=0;i<countPolygon;i++)
    {
        OPolygon * poly=new OPolygon();
        poly->setIsClosed(true);
        poly->fill(read);
        allPolygon.append(poly);
    }

    showAfterLoad();
    update();
}
//************************************************************
void Widget::drawAgain(ONode *again)
{
    movedNode *objMovedNode=new movedNode(again);
    int x=again->lastPoint.x();
    int y=again->lastPoint.y();
    objMovedNode->beforeMoved(x,y);  //for undo

    x=again->point->x();
    y=again->point->y();
    objMovedNode->afterMoved(x,y);  //for redo

//    again->setGeometry(again->cursor().pos().x()-5,again->cursor().pos().y()-5,10,10);
    again->setGeometry(again->point->x()-5,again->point->y()-5,10,10);
    update();

        undoList.append(objMovedNode);
}
//************************************************************
void Widget::drawAgainCircle(OCircle *againCircle)
{
    Undo4MovedCircle * objMovedCircle=new Undo4MovedCircle(againCircle);
    int x=againCircle->lastCenter.x();
    int y=againCircle->lastCenter.y();
    int r=againCircle->lastRadius;
    objMovedCircle->beforeMoved(x,y,r);

    x=againCircle->center.x();
    y=againCircle->center.y();
    r=againCircle->radius;
    objMovedCircle->afterMoved(x,y,r);

    againCircle->setGeometry(againCircle->center.x()-(againCircle->radius/2),
                             againCircle->center.y()-(againCircle->radius/2),
                             againCircle->radius,againCircle->radius);

    undoList.append(objMovedCircle);
    update();
}
//************************************************************
void Widget::drawAgainRectngle(ORectAngle *againRect)
{
    Undo4MovedRectangle * objMovedRect=new Undo4MovedRectangle(againRect);
    int x=againRect->lastFirstPoint.x();
    int y=againRect->lastFirstPoint.y();
    int w=againRect->lastSecondPoint.x();
    int h=againRect->lastSecondPoint.y();
    objMovedRect->beforeMoved(x,y,w,h);

    x=againRect->firstPoint.x();
    y=againRect->firstPoint.y();
    w=againRect->secondPoint.x();
    h=againRect->secondPoint.y();
    objMovedRect->afterMoved(x,y,w,h);

    if(againRect->firstPoint.x()<againRect->secondPoint.x()  &&  againRect->firstPoint.y() <againRect->secondPoint.y())   //top left to bottom right
    {
        againRect->setGeometry(againRect->firstPoint.x(),
                        againRect->firstPoint.y(),
                        againRect->secondPoint.x()-againRect->firstPoint.x(),
                        againRect->secondPoint.y()-againRect->firstPoint.y());
    }
    if(againRect->firstPoint.x()>againRect->secondPoint.x()  &&  againRect->firstPoint.y() < againRect->secondPoint.y())  //top right to bottom left
    {
        againRect->setGeometry(againRect->secondPoint.x(),
                          againRect->firstPoint.y(),
                          againRect->firstPoint.x()-againRect->secondPoint.x(),
                          againRect->secondPoint.y()-againRect->firstPoint.y());
    }
    if(againRect->firstPoint.x()>againRect->secondPoint.x() && againRect->firstPoint.y() >againRect->secondPoint.y())    //bottom right to top left
    {
        againRect->setGeometry(againRect->secondPoint.x(),
                          againRect->secondPoint.y(),
                          againRect->firstPoint.x()-againRect->secondPoint.x(),
                          againRect->firstPoint.y()-againRect->secondPoint.y());
    }
    if(againRect->firstPoint.x()<againRect->secondPoint.x() && againRect->firstPoint.y() >againRect->secondPoint.y())    //bottom left to top right
    {
        againRect->setGeometry(againRect->firstPoint.x(),
                          againRect->secondPoint.y(),
                          againRect->secondPoint.x()-againRect->firstPoint.x(),
                          againRect->firstPoint.y()-againRect->secondPoint.y());
    }

    update();

    undoList.append(objMovedRect);
}
//************************************************************
void Widget::slotUpdate()
{
    update();
}
//************************************************************
void Widget::slotUpdateRectangl()
{
    update();
}
//************************************************************
void Widget::slotUpdateCircle()
{
    update();
}
//************************************************************
void Widget::addPath()
{
    whichShape=pathEnum;
    flag=false;
}
//************************************************************
void Widget::drawCircle()
{
    whichShape=circleEnum;
    flag4Click=true;
    flag4Circle=true;
}
//************************************************************
void Widget::drawRectangle()
{
    whichShape=rectangleEnum;
    flag4Click=true;
    flag4Rectangle=true;
}
//************************************************************
void Widget::drawPolygon()
{
    whichShape=polygonEnum;
    flag4Click=true;
    flag4ControlPolygon=true;
}
//************************************************************
qint32 Widget::generateId()
{
    return LastId++;
}
//************************************************************
qint32 Widget::generateId4Rect()
{
    return LastId4Rect++;
}
//************************************************************
qint32 Widget::generateId4Circle()
{
    return LastId4Polygon++;
}
//************************************************************
qint32 Widget::generateId4Polygon()
{
    return LastId4Polygon++;
}
//************************************************************
void Widget::rectangleSetting(ORectAngle *rangle)
{
    rangle->visibility=false;
    objRect=new Undo4DeleteRect(rangle);
    rangle->setVisible(false);
    undoList.append(objRect);
update();
}
//************************************************************
void Widget::propertyRectangle(ORectAngle *rangleProperties)
{
    Undo4PropertyRect * objProperty;

    int x=rangleProperties->firstPoint.x();
    int y=rangleProperties->firstPoint.y();
    int w=abs(rangleProperties->secondPoint.x()-rangleProperties->firstPoint.x());
    int h=abs(rangleProperties->secondPoint.y()-rangleProperties->firstPoint.y());

    objProperty=new Undo4PropertyRect(rangleProperties);
    objProperty->firstRect(x,y,w,h);
    undoList.append(objProperty);

    rangleProperties->getPop->showInfo(x,y,w,h);

    rangleProperties->x_temp=rangleProperties->firstPoint.x();
    rangleProperties->y_temp=rangleProperties->firstPoint.y();
    rangleProperties->width_temp=abs(rangleProperties->secondPoint.x()-rangleProperties->firstPoint.x());
    rangleProperties->height_temp=abs(rangleProperties->secondPoint.y()-rangleProperties->firstPoint.y());

    if(rangleProperties->getPop->exec()==QDialog::Accepted)
     {
        rangleProperties->getPop->changed();
        if(rangleProperties->x_temp!=rangleProperties->getPop->x_Number)
        {
         rangleProperties->firstPoint.setX(rangleProperties->getPop->x_Number);
        }

        if(rangleProperties->y_temp!=rangleProperties->getPop->y_Number)
        {
            rangleProperties->firstPoint.setY(rangleProperties->getPop->y_Number);
        }

        if(rangleProperties->width_temp!=rangleProperties->getPop->width_Number)   //for width of rectangle
        {

            if(rangleProperties->firstPoint.x()<rangleProperties->secondPoint.x()  &&  rangleProperties->firstPoint.y() <rangleProperties->secondPoint.y())   //top left to bottom right
            {
                rangleProperties->secondPoint.setX(rangleProperties->firstPoint.x() + rangleProperties->getPop->width_Number);
            }

            if(rangleProperties->firstPoint.x()>rangleProperties->secondPoint.x()  &&  rangleProperties->firstPoint.y() < rangleProperties->secondPoint.y())  //top right to bottom left
            {
                 rangleProperties->secondPoint.setX(rangleProperties->firstPoint.x() - rangleProperties->getPop->width_Number);
            }

            if(rangleProperties->firstPoint.x()>rangleProperties->secondPoint.x() && rangleProperties->firstPoint.y() >rangleProperties->secondPoint.y())    //bottom right to top left
            {
                 rangleProperties->secondPoint.setX(rangleProperties->firstPoint.x() - rangleProperties->getPop->width_Number);
            }

            if(rangleProperties->firstPoint.x()<rangleProperties->secondPoint.x() && rangleProperties->firstPoint.y() >rangleProperties->secondPoint.y())    //bottom left to top right
            {
                rangleProperties->secondPoint.setX(rangleProperties->firstPoint.x() + rangleProperties->getPop->width_Number);
            }

        }

        if(rangleProperties->height_temp!=rangleProperties->getPop->height_Number) //for height of rectangle
        {
            if(rangleProperties->firstPoint.x()<rangleProperties->secondPoint.x()  &&  rangleProperties->firstPoint.y() <rangleProperties->secondPoint.y())   //top left to bottom right
            {
                rangleProperties->secondPoint.setY(rangleProperties->firstPoint.y() + rangleProperties->getPop->height_Number);
            }

            if(rangleProperties->firstPoint.x()>rangleProperties->secondPoint.x()  &&  rangleProperties->firstPoint.y() < rangleProperties->secondPoint.y())  //top right to bottom left
            {
                 rangleProperties->secondPoint.setY(rangleProperties->firstPoint.y() + rangleProperties->getPop->height_Number);
            }

            if(rangleProperties->firstPoint.x()>rangleProperties->secondPoint.x() && rangleProperties->firstPoint.y() >rangleProperties->secondPoint.y())    //bottom right to top left
            {
                 rangleProperties->secondPoint.setY(rangleProperties->firstPoint.y() - rangleProperties->getPop->height_Number);
            }

            if(rangleProperties->firstPoint.x()<rangleProperties->secondPoint.x() && rangleProperties->firstPoint.y() >rangleProperties->secondPoint.y())    //bottom left to top right
            {
                rangleProperties->secondPoint.setY(rangleProperties->firstPoint.y() - rangleProperties->getPop->height_Number);
            }
        }

     }

    x=rangleProperties->firstPoint.x();
    y=rangleProperties->firstPoint.y();
    w=abs(rangleProperties->secondPoint.x()-rangleProperties->firstPoint.x());
    h=abs(rangleProperties->secondPoint.y()-rangleProperties->firstPoint.y());

    //set geometry for changing property
    if(rangleProperties->firstPoint.x()<rangleProperties->secondPoint.x()  &&  rangleProperties->firstPoint.y() <rangleProperties->secondPoint.y())   //top left to bottom right
    {
        rangleProperties->setGeometry(rangleProperties->firstPoint.x(),
                        rangleProperties->firstPoint.y(),
                        rangleProperties->secondPoint.x()-rangleProperties->firstPoint.x(),
                        rangleProperties->secondPoint.y()-rangleProperties->firstPoint.y());
    }
    if(rangleProperties->firstPoint.x()>rangleProperties->secondPoint.x()  &&  rangleProperties->firstPoint.y() < rangleProperties->secondPoint.y())  //top right to bottom left
    {
        rangleProperties->setGeometry(rangleProperties->secondPoint.x(),
                          rangleProperties->firstPoint.y(),
                          rangleProperties->firstPoint.x()-rangleProperties->secondPoint.x(),
                          rangleProperties->secondPoint.y()-rangleProperties->firstPoint.y());
    }
    if(rangleProperties->firstPoint.x()>rangleProperties->secondPoint.x() && rangleProperties->firstPoint.y() >rangleProperties->secondPoint.y())    //bottom right to top left
    {
        rangleProperties->setGeometry(rangleProperties->secondPoint.x(),
                          rangleProperties->secondPoint.y(),
                          rangleProperties->firstPoint.x()-rangleProperties->secondPoint.x(),
                          rangleProperties->firstPoint.y()-rangleProperties->secondPoint.y());
    }
    if(rangleProperties->firstPoint.x()<rangleProperties->secondPoint.x() && rangleProperties->firstPoint.y() >rangleProperties->secondPoint.y())    //bottom left to top right
    {
        rangleProperties->setGeometry(rangleProperties->firstPoint.x(),
                          rangleProperties->secondPoint.y(),
                          rangleProperties->secondPoint.x()-rangleProperties->firstPoint.x(),
                          rangleProperties->firstPoint.y()-rangleProperties->secondPoint.y());
    }

    objProperty->secondRect(x,y,w,h);
}
//************************************************************
void Widget::circleSetting(OCircle *cir)
{
    cir->visibility=false;
    objCircle=new Undo4DeleteCircle(cir);
    cir->setVisible(false);
    undoList.append(objCircle);
update();
}
//************************************************************
void Widget::propertyCircle(OCircle *circleProperties)
{
    Undo4PropertyCircle * objProperty;
    int a=circleProperties->center.x();
    int b=circleProperties->center.y();
    qint32 r=circleProperties->radius;

    objProperty=new Undo4PropertyCircle(circleProperties);
    objProperty->firstCircle(a,b,r);
    undoList.append(objProperty);

    circleProperties->getPop->showInfo(a,b,r);

    circleProperties->x_temp=circleProperties->center.x();
    circleProperties->y_temp=circleProperties->center.y();
    circleProperties->radius_temp=circleProperties->radius;

    if(circleProperties->getPop->exec()==QDialog::Accepted)
     {
        circleProperties->getPop->changed();

        if(circleProperties->x_temp!=circleProperties->getPop->x_number)
        {
            circleProperties->center.setX(circleProperties->getPop->x_number);
        }
        if(circleProperties->y_temp!=circleProperties->getPop->y_number)
        {
            circleProperties->center.setY(circleProperties->getPop->y_number);
        }
        if(circleProperties->radius_temp!=circleProperties->getPop->radius_number)
        {
            circleProperties->radius=circleProperties->getPop->radius_number;
        }
     }

    a=circleProperties->center.x();
    b=circleProperties->center.y();
    r=circleProperties->radius;
    circleProperties->setGeometry(circleProperties->center.x()-(circleProperties->radius/2),
                                  circleProperties->center.y()-(circleProperties->radius/2),
                                  circleProperties->radius,
                                  circleProperties->radius);
    objProperty->secondCircle(a,b,r);
}
//************************************************************
void Widget::polygonNodeSetting(ONode *node)
{
   node->visibility=false;
   objPolygonNode=new Undo4PolygonsNode(node);
   node->setVisible(false);
   undoList.append(objPolygonNode);


update();
}
//************************************************************
void Widget::polygonSetting(ONode *node)
{
    UndoDeletePolygon * objPolygon;
    objPolygon=new UndoDeletePolygon(node);
    undoList.append(objPolygon);
    int first;
    for(int i=0;i<allPolygon.size();i++)
        {
            for(int j=0;j<allPolygon.at(i)->onePoly.size();j++)
            {
                if (node == allPolygon.at(i)->onePoly.at(j))
                {
                    allPolygon.at(i)->setIsClosed(false);

//                    objPolygon->checkPolygonNodes(allPolygon.at(i)->onePoly);
                    objPolygon->checkPolygonNodes(allPolygon,i);

                    first=0;
                    while(first!=(allPolygon.at(i)->onePoly.size()))
                        {
                            allPolygon.at(i)->onePoly.at(first)->visibility=false;
                            allPolygon.at(i)->onePoly.at(first)->setVisible(false);
                            first++;
                        }
                }
            }
        }
    update();
}
//************************************************************
void Widget::propertyPolygon(ONode *polygonProperty)
{
    Undo4PropertyPolygon *objProperty;

    int a=polygonProperty->point->x();
    int b=polygonProperty->point->y();

    objProperty=new Undo4PropertyPolygon(polygonProperty);
    objProperty->firstNode(a,b);
    undoList.append(objProperty);

    polygonProperty->getPopPolygon->showInfo(polygonProperty->point->x(),polygonProperty->point->y());

     polygonProperty->x_temp=polygonProperty->point->x();
     polygonProperty->y_temp=polygonProperty->point->y();

    if(polygonProperty->getPopPolygon->exec()==QDialog::Accepted)
     {
         polygonProperty->getPopPolygon->changed();
        if(polygonProperty->x_temp!=polygonProperty->getPopPolygon->x_number)
        {
            polygonProperty->point->setX(polygonProperty->getPopPolygon->x_number);
        }
        if (polygonProperty->y_temp!=polygonProperty->getPopPolygon->y_number)
        {
            polygonProperty->point->setY(polygonProperty->getPopPolygon->y_number);
        }

        a=polygonProperty->point->x();
        b=polygonProperty->point->y();
    }
     polygonProperty->setGeometry(polygonProperty->point->x()-5,polygonProperty->point->y()-5,10,10);

     objProperty->secondNode(a,b);

}

