#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

// g++ -std=c++11 -O3 -Wall main.cpp -lm

#include "main.h"

int main () {
    int D1, D2, n;

    std::cin >> D1; std::cin >> D2; std::cin >> n;
    std::list<peca> dim;//[n+1];
    int max = 0;

    for(int i = 0; i < n; i++) {
        int a,b,c;
        std::cin >> a; std::cin >> b; std::cin >> c;
        peca p;
        p.d1 = a;
        p.d2 = b;
        p.p = c;

        dim.push_front(p);
    }

    // print da lista
    // for (peca peca : dim) {
    //     std::cout << "(" << peca.d1 << ", " << peca.d2 << ", " << peca.p << ") ";
    // }

    // Filtra a lista pelas peças que não cabem na dimensão da original
    dim.remove_if([D1, D2](const peca& peca) {
        return (peca.d1 > D1 && peca.d2 > D2) || (peca.d1 > D2 && peca.d2 > D1); 
    });

    std::vector<peca> vetor(dim.begin(), dim.end());

    for (int i = 0; i < dim.size(); i++) {
        int mdc = vetor[i].d1 / D1 ;
        if(vetor[i].d2/D2 < mdc) mdc = vetor[i].d2/D2;
        if(vetor[i].d1/D1 == 0 && vetor[i].d2/D2 == 0 && vetor[i].d1/D2 == 0 && vetor[i].d2/D1 == 0) {
            // se a peca couber na original e for a maior peça
            // já n sei oq estou a fazer :)
            // pls help
        }

        // for (int j = i; j < dim.size(); j++) {
            
        // }   
    }

    std::cout << max << "\n";

    return 0;
}