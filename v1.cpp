#include "proj2.h"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {

    int X, Y, n;
    std::cin >> X; std::cin >> Y; std::cin >> n;

    int W = (X+1) * (Y+1);
    piece *lista[W];
    for (int i=0, f=0; i<=X; i++) 
        for (int j=0; j<=Y; j++)
            lista[f++] = new piece(i, j, 0);

    for (int i=0; i<n; i++) {
        int ai, bi, pi;
        std::cin >> ai; std::cin >> bi; std::cin >> pi;
        if (ai*Y + ai + bi < W)
            lista[ai*Y + ai + bi]->setP(pi);
        if (bi*Y + bi + ai < W)
            lista[bi*Y + bi + ai]->setP(pi);
    }

    for (int k=1; k<W; k++) {
        piece* p = lista[k];
        std::vector<std::tuple<piece*, piece*>> v;
        for (int i=1; i<=p->getA()/2; i++)
            v.push_back(std::make_tuple(lista[i*Y + i + p->getB()], lista[(p->getA()-i)*Y + p->getB() + (p->getA()-i)]));
        for (int i=1; i<=p->getB()/2; i++)
            v.push_back(std::make_tuple(lista[p->getA()*Y + p->getA() + i], lista[p->getA()*Y + p->getA() + (p->getB()-i)]));
        int max = 0;
        for (auto it=v.begin(); it!=v.end(); it++) {
            piece* p1 = std::get<0>(*it);
            piece* p2 = std::get<1>(*it);
            max = std::max(p->getP(), lista[p1->getA()*Y + p1->getA() + p1->getB()]->getP() + lista[p2->getA()*Y + p2->getA() + p2->getB()]->getP());
            p->setP(max);
        }
    }

    std::cout << lista[W-1]->getP() << "\n";

    return 0;
}