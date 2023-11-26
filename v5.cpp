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
            for(int k = 1; k <= i/2; k++) {
                maxPrice = std::max(maxPrice, placa[k][j] + placa[i-k][j]);
            }

            // Fixando a linha e somando com as peças que estão na mesma linha
            for(int k = 1; k <= j/2; k++) {
                maxPrice = std::max(maxPrice, placa[i][j] + placa[i][j-k]);
            }

            placa[i][j] = maxPrice;
        }
    }

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
