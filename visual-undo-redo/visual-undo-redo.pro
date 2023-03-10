#-------------------------------------------------
#
# Project created by QtCreator 2014-01-20T05:37:13
#
#-------------------------------------------------

QT       += core
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 5)

TARGET = visual-undo-redo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    otarget.cpp \
    onode.cpp \
    simpleShapeDialog.cpp \ 
    history.cpp \
    action.cpp \
    changingproperty.cpp \
    deletenode.cpp \
    deletetarget.cpp \
    movednode.cpp \
    ocircle.cpp \
    orectangle.cpp \
    opolygon.cpp \
    simpleshaperectangle.cpp \
    simpleshapecircle.cpp \
    undo4deleterect.cpp \
    undo4deletecircle.cpp \
    undo4propertycircle.cpp \
    undo4propertyrect.cpp \
    simpleshapepolygon.cpp \
    undo4polygonsnode.cpp \
    undodeletepolygon.cpp \
    undo4propertypolygon.cpp \
    undo4movedcircle.cpp \
    undo4movedrectangle.cpp \
    resizeRectangle.cpp


HEADERS  += widget.h \
    otarget.h \
    onode.h \
    simpleShapeDialog.h \ 
    history.h \
    action.h \
    changingproperty.h \
    deletenode.h \
    deletetarget.h \
    movednode.h \
    orectangle.h \
    opolygon.h \
    ocircle.h \
    orectangle.h \
    opolygon.h \
    simpleshaperectangle.h \
    simpleshapecircle.h \
    undo4deleterect.h \
    undo4deletecircle.h \
    undo4propertycircle.h \
    undo4propertyrect.h \
    simpleshapepolygon.h \
    undo4polygonsnode.h \
    undodeletepolygon.h \
    undo4propertypolygon.h \
    undo4movedcircle.h \
    undo4movedrectangle.h \
    resizeRectangle.h
   
FORMS    += simpleshapedialog.ui \
    simpleShapeCircle.ui \
    simpleShapeRectangle.ui \
    simpleshapepolygon.ui

RESOURCES += \
    rsc.qrc
