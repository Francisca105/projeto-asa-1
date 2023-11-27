#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

int main() {
    int X, Y, n;
    std::cin >> X >> Y >> n;

    if (X > Y) 
        std::swap(X, Y);

    int T = X*Y - X*(X-1)/2;
    
    std::vector<int> ll(T);

    for (int i=0; i<n; i++) {
        int ai, bi, pi;
        std::cin >> ai; std::cin >> bi; std::cin >> pi;

        if (ai <= X && bi <= Y && ai <= bi)
            ll[Y*ai - Y - (ai-2)*(ai-1)/2 + (bi-ai)] = pi;

        else if (bi <= X && ai <= Y && bi <= ai)
            ll[Y*bi - Y - (bi-2)*(bi-1)/2 + (ai-bi)] = pi;
    }

    for (int i=1; i<=X; i++) {
        for (int j=i; j<=Y; j++) {
            int max = ll[Y*i - Y - (i-2)*(i-1)/2 + (j-i)];

            for (int k=1; k<=i/2; k++) {
                max = std::max(max, ll[Y*k - Y - (k-2)*(k-1)/2 + (j-k)] + ll[Y*(i-k) - Y - (i-k-2)*(i-k-1)/2 + (j-(i-k))]);
            }

            for (int k=1; k<=j/2; k++) {
                if (i > k && i > j-k)
                    max = std::max(max, ll[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + ll[Y*(j-k) - Y - (j-k-2)*(j-k-1)/2 + (i-(j-k))]);

                else if (i > k)
                    max = std::max(max, ll[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + ll[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)]);

                else
                    max = std::max(max, ll[Y*i - Y - (i-2)*(i-1)/2 + (k-i)] + ll[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)]);
            }

            ll[Y*i - Y - (i-2)*(i-1)/2 + (j-i)] = max;
        }
    }

    std::cout << ll[T-1] << "\n";
    return 0;
}