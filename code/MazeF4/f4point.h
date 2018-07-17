#ifndef F4POINT_H
#define F4POINT_H
#include <QDebug>

class F4point
{
public:
    int x, y;
    F4point();
    F4point(int x, int y);
    int get_x();
    int get_y();
    friend QDebug operator<<(QDebug debug, const F4point &c);
};

#endif // F4POINT_H
