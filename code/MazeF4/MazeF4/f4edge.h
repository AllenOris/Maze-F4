#ifndef F4EDGE_H
#define F4EDGE_H


class F4edge
{
public:
    int from, to, w;
    F4edge();
    F4edge(int f,int t);
    F4edge(int f,int t,int w);
    bool operator<(const F4edge &E);
};

#endif // F4EDGE_H
