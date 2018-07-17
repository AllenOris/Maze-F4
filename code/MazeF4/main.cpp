#include "widget.h"
#include <QApplication>
#include "f4mazemap.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    w.show();

    return a.exec();
}
