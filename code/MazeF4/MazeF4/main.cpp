#include "widget.h"
#include <QApplication>
#include "f4mazemap.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}