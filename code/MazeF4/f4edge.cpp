#include "f4edge.h"

F4edge::F4edge()
{

}

F4edge::F4edge(int f, int t):from(f),to(t){
}

F4edge::F4edge(int f, int t, int w):from(f),to(t),w(w){

}

bool F4edge::operator<(const F4edge&E)
{
    return this->w<E.w;
}

bool operator <(const F4edge &A, const F4edge &B)
{
    return A.w<B.w;
}

F4edge F4edge::reverse()
{
    return F4edge(this->to,this->from,this->w);
}
