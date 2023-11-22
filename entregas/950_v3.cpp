#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

class piece {
    public:
        piece(int a, int b, int p) {
            this->a = a;
            this->b = b;
            this->p = p;
        }
        int getA() { return this->a; }
        int getB() { return this->b; }
        int getP() { return this->p; }
        void setP(int p) { this->p = p; }
    private:
        int a;
        int b;
        int p;
};

int main() {

    int X, Y, n, max;
    std::cin >> X; std::cin >> Y; std::cin >> n;

    int l[X+1][Y+1];
    for (int i=0; i<=X; i++) 
        for (int j=0; j<=Y; j++)
            l[i][j] = 0;

    for (int i=0; i<n; i++) {
        int ai, bi, pi;
        std::cin >> ai; std::cin >> bi; std::cin >> pi;
        if (ai <= X && bi <= Y)
            l[ai][bi] = pi;
        if (bi <= X && ai <= Y)
            l[bi][ai] = pi;
    }

    for (int i=1; i<=X; i++) {
        for (int j=1; j<=Y; j++) {
            std::vector<std::tuple<int, int>> v;
            for (int k=1; k<=i/2; k++)
                v.push_back(std::make_tuple(l[k][j], l[i-k][j]));
            for (int k=1; k<=j/2; k++)
                v.push_back(std::make_tuple(l[i][k], l[i][j-k]));
            max = 0;
            for (auto it=v.begin(); it!=v.end(); it++) {
                int p1 = std::get<0>(*it);
                int p2 = std::get<1>(*it);
                max = std::max(l[i][j], p1 + p2);
                l[i][j] = max;
            }
        }
    }

    std::cout << l[X][Y] << "\n";

    return 0;
}