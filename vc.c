#include <stdio.h>
#include <stdlib.h>


int main() {

    int X, Y, n;
    scanf("%d %d %d", &X, &Y, &n);

    // nenhuma peça a ser produzida, o valor é 0
    if (n == 0) {
        printf("%d\n", 0);
        return 0;
    }

    // apenas uma peça a ser produzida, o valor pode ser calculado diretamente
    if (n == 1) {
        int ai, bi, pi;
        scanf("%d %d %d", &ai, &bi, &pi);
        // calcula o número máximo de peças que cabem na placa
        if ((int)X/ai*Y/bi > (int)X/bi*Y/ai)
            printf("%d\n", (int)X/ai*Y/bi*pi);
        else
            printf("%d\n", (int)X/bi*Y/ai*pi);
        return 0;
    }

    // para esta solução, é necessário que Y seja maior ou igual a X
    if (X > Y) {int t = X; X = Y; Y = t;}

    // os valores associados a cada peça vão ser guardadas num vetor que simula a parte diagonal
    // superior da matriz de dimensões X por Y (inclui a diagonal) (a matriz pode não ser quadrada)
    int tamanho = X*Y - X*(X-1)/2;
    int *lista = (int*)malloc(tamanho * sizeof(int));

    // variáveis auxiliares para guardar a menor peça a ser produzida
    // permitem saltar o cálculo do valor de peças que invariavelmente seria 0
    int x = 10e8, y = 10e8;

    for (int i=0; i<n; i++) {
        int ai, bi, pi;
        scanf("%d %d %d", &ai, &bi, &pi);
        if (ai > bi) {int t = ai; ai = bi; bi = t;}
        if (ai <= X && bi <= Y) {
            lista[Y*ai - Y - (ai-2)*(ai-1)/2 + (bi-ai)] = pi;
            // condição para o cálculo das variáveis auxiliares
            if (x >= ai) {
                x = ai;
                if (y >= bi)
                    y = bi;
            }
        }
    }

    for (int i=1; i<=X; i++) {
        for (int j=i; j<=Y; j++) {
            // salta as peças mais pequenas cujo valor é 0
            if (i < x || (i == x && j < y))
                continue;
            // indíce da peça (i, j)
            int indice = Y*i - Y - (i-2)*(i-1)/2 + (j-i);
            int max = lista[indice];
            // calcula o valor máximo entre os possíveis cortes horizontais da peça (i, j)
            for (int k=1; k<=i/2; k++)
                max = max >= lista[Y*k - Y - (k-2)*(k-1)/2 + (j-k)] + lista[Y*(i-k) - Y - (i-k-2)*(i-k-1)/2 + (j-(i-k))] ?
                max :
                lista[Y*k - Y - (k-2)*(k-1)/2 + (j-k)] + lista[Y*(i-k) - Y - (i-k-2)*(i-k-1)/2 + (j-(i-k))];
            // calcula o valor máximo entre os possíveis cortes verticais da peça (i, j)
            // as diferentes condições são necessárias devido à forma como o vetor foi construído
            for (int k=1; k<=j/2; k++) {
                if (i > k && i > j-k)
                    max = max >= lista[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + lista[Y*(j-k) - Y - (j-k-2)*(j-k-1)/2 + (i-(j-k))] ?
                    max :
                    lista[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + lista[Y*(j-k) - Y - (j-k-2)*(j-k-1)/2 + (i-(j-k))];
                else if (i > k)
                    max = max >= lista[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + lista[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)] ?
                    max :
                    lista[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + lista[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)];
                else
                    max = max >= lista[Y*i - Y - (i-2)*(i-1)/2 + (k-i)] + lista[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)] ?
                    max :
                    lista[Y*i - Y - (i-2)*(i-1)/2 + (k-i)] + lista[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)];
            }
            // atualiza o valor máximo da peça (i, j)
            lista[indice] = max;
        }
    }

    printf("%d\n", lista[tamanho-1]);

    free(lista);

    return 0;
}
