#include "proj.h"

#include <stdlib.h>
#include <iostream>
#include <algorithm>

int main() {

    int X, Y, n;
    std::cin >> X; std::cin >> Y; std::cin >> n;
    int W = (X+1) * (Y+1);

    p_piece dp[W]; // represents the max value of the piece with dimensions i,j
    for (int i=0, f=0; i<=X; i++) 
        for (int j=0; j<=Y; j++, f++) {
            dp[f] = (p_piece) malloc(sizeof(struct piece));
            dp[f]->a = i; dp[f]->b = j; dp[f]->p = 0;
            }

    for (int i=0; i<n; i++) {
        int ai, bi, pi;
        std::cin >> ai; std::cin >> bi; std::cin >> pi;
        dp[ai*Y + bi + ai]->p = pi;
    }

    int k, l;
    for (int i=0; i<W; i++) 
        for (int j=0; j<W; j++) {
            if (dp[j]->a <= dp[i]->a && dp[j]->b <= dp[i]->b) {
                p_piece aux1 = (p_piece) malloc(sizeof(struct piece));
                aux1->a = dp[i]->a - dp[j]->a;
                aux1->b = dp[i]->b;
                p_piece aux2 = (p_piece) malloc(sizeof(struct piece));
                aux2->a = dp[i]->a;
                aux2->b = dp[i]->b - dp[j]->b;
                for (k=0; k<W; k++)
                    if (aux1->a == dp[k]->a && aux1->b == dp[k]->b)
                        break;
                for (l=0; l<W; l++)
                    if (aux2->a == dp[l]->a && aux2->b == dp[l]->b)
                        break;
                dp[i]->p = std::max(dp[i]->p, std::max(dp[k]->p,dp[l]->p) + dp[j]->p);
            }
        }

//    for (int i=0; i<W; i++)
//        cout << dp[i]->p << " ";
    std::cout << dp[W-1]->p << "\n";

    return 0;
}