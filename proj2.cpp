#include "proj2.h"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int a(piece* p, piece* lista[], piece* given[], int n, int Y) {
    if (p->getA() == 0 || p->getB() == 0)
        return 0;
    for (int i=0; i<n; i++)
        if (p->getA() == given[i]->getA() && p->getB() == given[i]->getB())
            return given[i]->getP();
    std::vector<std::tuple<piece*, piece*>> v;
    for (int i=1; i<=p->getA()/2; i++)
        v.push_back(std::make_tuple(lista[i*Y + i + p->getB()], lista[(p->getA()-i)*Y + p->getB() + (p->getA()-i)]));
    for (int i=1; i<=p->getB()/2; i++)
        v.push_back(std::make_tuple(lista[p->getA()*Y + p->getA() + i], lista[p->getA()*Y + p->getA() + (p->getB()-i)]));
    int max = 0;
    for (auto it=v.begin(); it!=v.end(); it++)
        max = std::max(max, a(std::get<0>(*it), lista, given, n, Y) + a(std::get<1>(*it), lista, given, n, Y));
    return max;
}

int main() {

    int X, Y, n;
    std::cin >> X; std::cin >> Y; std::cin >> n;

    int W = (X+1) * (Y+1);
    piece *lista[W], *given[n];
    for (int i=0, f=0; i<=X; i++) 
        for (int j=0; j<=Y; j++, f++)
            lista[f] = new piece(i, j, 0);

    for (int i=0; i<n; i++) {
        int ai, bi, pi;
        std::cin >> ai; std::cin >> bi; std::cin >> pi;
        lista[ai*Y + ai + bi]->setP(pi);
        given[i] = new piece(ai, bi, pi);
    }

    std::cout << a(lista[W-1], lista, given, n, Y) << "\n";

    return 0;
}