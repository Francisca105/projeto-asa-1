#include <iostream>
#include <list>
#include <vector>

#include "main.h"

int main () {
    int D1, D2, n;

    std::cin >> D1; std::cin >> D2; std::cin >> n;
    std::list<peca> * dim = new std::list<peca>[n+1];

    for(int i = 0; i < n; i++) {
        int a,b,c;
        std::cin >> a; std::cin >> b; std::cin >> c;
        peca p;
        p.d1 = a;
        p.d2 = b;
        p.p = c;

        dim[i].push_front(p);
    }
}