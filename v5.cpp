#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

int main() {

    int width, height, n;
    std::cin >> width; std::cin >> height; std::cin >> n;

    if (height > width) {
        int temp = width;
        width = height;
        height = temp;
    }

    std::vector<std::vector<int>> placa(width, std::vector<int>(height, 0));

    for(int i = 0; i < n; i++) {
        int a,b,p;
        std::cin >> a; std::cin >> b; std::cin >> p;
        if(b > a)
            placa[b - 1][a - 1] = p;
        else
            placa[a - 1][b - 1] = p; 
    }

    // printf("Original:\n");
    // for(int i = 0; i < width; i++) {
    //     for(int j = 0; j < height; j++) {
    //         printf("%d ", placa[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    for(int i = 0; i < width; i++) { // Linha
        for(int j = 0; j < height; j++) { // Coluna
            int maxPrice = placa[i][j];

            // Fixando a coluna e somando com as peças que estão na mesma coluna
            for(int k = 0; k <= i/2; k++) {
                maxPrice = std::max(maxPrice, placa[k][j] + placa[i-k][j]);
            }

            // Fixando a linha e somando com as peças que estão na mesma linha
            for(int k = 0; k <= j/2; k++) {
                maxPrice = std::max(maxPrice, placa[i][j] + placa[i][j-k]);
            }

            placa[i][j] = maxPrice;
        }
    }

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            printf("%d ", placa[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // if (width > height) {
    //     int temp = width;
    //     width = height;
    //     height = temp;
    // }

    // std::vector<std::vector<int>> list(width, std::vector<int>(height, 0));

    // for(int i = 0; i < n; i++) {
    //     int a,b,p;
    //     std::cin >> a; std::cin >> b; std::cin >> p;
    //     if(a > b) {
    //         int temp = a;
    //         a = b;
    //         b = temp;
    //     }
    //     list[a - 1][b - 1] = p;
    // }

    // // printf("Original:\n");
    // // for(int i = 1; i <= width; i++) {
    // //     for(int j = 1; j <= height; j++) {
    // //         printf("%d ", list[i][j]);
    // //     }
    // //     // printf("\n");
    // // }
    // // printf("\n");

    // for(int i = 0; i <= width; i++) {
    //     for(int j = 0; j <= height; j++) {
    //         int maxPrice = list[i][j];
            
    //         for(int k = 0; k <= i/2; k++) {
    //             maxPrice = std::max(maxPrice, list[k][j] + list[i-k][j]);
    //         }

    //         for(int k = 0; k <= i/2; k++) {
    //             maxPrice = std::max(maxPrice, list[i][j - k] + list[i][k]);
    //         }

    //         if(maxPrice > list[i][j]) {
    //             list[i][j] = maxPrice;
    //         }
    //     }
    // }

    // // printf("Original:\n");
    // // for(int i = 1; i <= width; i++) {
    // //     for(int j = 1; j <= height; j++) {
    // //         printf("%d ", list[i][j]);
    // //     }
    // //     // printf("\n");
    // // }
    // // printf("\n");

    // // int T = X*Y - X*(X-1)/2;
    
    
    // // int ll[T];
    // // memset(ll, 0, sizeof(ll));

    // // for (int i=0; i<n; i++) {
    // //     int ai, bi, pi;
    // //     std::cin >> ai; std::cin >> bi; std::cin >> pi;
    // //     if (ai <= X && bi <= Y && ai <= bi)
    // //         ll[Y*ai - Y - (ai-2)*(ai-1)/2 + (bi-ai)] = pi;
    // //     else if (bi <= X && ai <= Y && bi <= ai)
    // //         ll[Y*bi - Y - (bi-2)*(bi-1)/2 + (ai-bi)] = pi;
    // // }

    // // for (int i=1; i<=X; i++) {
    // //     for (int j=i; j<=Y; j++) {
    // //         int max = ll[Y*i - Y - (i-2)*(i-1)/2 + (j-i)];
    // //         for (int k=1; k<=i/2; k++) {
    // //             max = std::max(max, ll[Y*k - Y - (k-2)*(k-1)/2 + (j-k)] + ll[Y*(i-k) - Y - (i-k-2)*(i-k-1)/2 + (j-(i-k))]);
    // //         }
    // //         for (int k=1; k<=j/2; k++) {
    // //             if (i > k && i > j-k) {
    // //                 max = std::max(max, ll[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + ll[Y*(j-k) - Y - (j-k-2)*(j-k-1)/2 + (i-(j-k))]);
    // //             }
    // //             else if (i > k) {
    // //                 max = std::max(max, ll[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + ll[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)]);
    // //             }
    // //             else {
    // //                 max = std::max(max, ll[Y*i - Y - (i-2)*(i-1)/2 + (k-i)] + ll[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)]);
    // //             }
    // //         }
    // //         ll[Y*i - Y - (i-2)*(i-1)/2 + (j-i)] = max;
    // //     }
    // // }

    // printf("After:\n");
    // for(int i = 0; i < width; i++) {
    //     for(int j = 0; j < height; j++) {
    //         printf("%d ", placa[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    std::cout << placa[width-1][height-1] << "\n";

    return 0;
}
