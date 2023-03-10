#include <QtWidgets/QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.setWindowState(Qt::WindowMaximized);
    w.setWindowTitle("undo redo example");
    w.show();

    return a.exec();
}
