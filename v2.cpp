#include "proj2.h"

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {

    int X, Y, n;
    std::cin >> X; std::cin >> Y; std::cin >> n;

    int W = X * Y;
    piece *lista[W];
    for (int i=1, f=0; i<=X; i++) 
        for (int j=1; j<=Y; j++)
            lista[f++] = new piece(i, j, 0);

    for (int i=0; i<n; i++) {
        int ai, bi, pi;
        std::cin >> ai; std::cin >> bi; std::cin >> pi;
        if ((ai-1)*Y + (bi-1) < W)
            lista[(ai-1)*Y + (bi-1)]->setP(pi);
        if ((bi-1)*Y + (ai-1) < W)
            lista[(bi-1)*Y + (ai-1)]->setP(pi);
    }

    for (int k=1; k<W; k++) {
        piece* p = lista[k];
        std::vector<std::tuple<piece*, piece*>> v;
        for (int i=1; i<=p->getA()/2; i++)
            v.push_back(std::make_tuple(lista[(i-1)*Y + (p->getB()-1)], lista[(p->getA()-i-1)*Y + (p->getB()-1)]));
        for (int i=1; i<=p->getB()/2; i++)
            v.push_back(std::make_tuple(lista[(p->getA()-1)*Y + (i-1)], lista[(p->getA()-1)*Y + (p->getB()-i-1)]));
        int max = 0;
        for (auto it=v.begin(); it!=v.end(); it++) {
            piece* p1 = std::get<0>(*it);
            piece* p2 = std::get<1>(*it);
            max = std::max(p->getP(), lista[(p1->getA()-1)*Y + (p1->getB()-1)]->getP() + lista[(p2->getA()-1)*Y + (p2->getB()-1)]->getP());
            p->setP(max);
        }
    }

    std::cout << lista[W-1]->getP() << "\n";

    return 0;
}