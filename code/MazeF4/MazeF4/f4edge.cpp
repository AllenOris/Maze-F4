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
