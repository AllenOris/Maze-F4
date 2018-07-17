#include "f4point.h"

F4point::F4point()
{

}

F4point::F4point(int x, int y):x(x),y(y)
{
}

int F4point::get_x()
{
    return this->x;
}

int F4point::get_y()
{
    return this->y;
}

QDebug operator<<(QDebug debug, const F4point &c)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << '(' << c.x << ", " << c.y << ')';
    return debug;
}
