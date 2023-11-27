#include <stdio.h>
#include <stdlib.h>


int main() {

    int X, Y, n;
    scanf("%d %d %d", &X, &Y, &n);

    if (n == 0) {
        printf("%d\n", 0);
        return 0;
    }

    if (n == 1) {
        int ai, bi, pi;
        scanf("%d %d %d", &ai, &bi, &pi);
        if ((int)X/ai*Y/bi > (int)X/bi*Y/ai)
            printf("%d\n", (int)X/ai*Y/bi*pi);
        else
            printf("%d\n", (int)X/bi*Y/ai*pi);
        return 0;
    }

    if (X > Y) {int t = X; X = Y; Y = t;}

    int T = X*Y - X*(X-1)/2;
    int *ll = (int*)malloc(sizeof(int)*T);

    int x = 10e8, y = 10e8;

    for (int i=0; i<n; i++) {
        int ai, bi, pi;
        scanf("%d %d %d", &ai, &bi, &pi);
        if (ai > bi) {int t = ai; ai = bi; bi = t;}
        if (ai <= X && bi <= Y) {
            ll[Y*ai - Y - (ai-2)*(ai-1)/2 + (bi-ai)] = pi;
            if (x >= ai) {
                x = ai;
                if (y >= bi)
                    y = bi;
            }
        }
    }

    for (int i=1; i<=X; i++) {
        for (int j=i; j<=Y; j++) {
            if (i < x || (i == x && j < y))
                continue;
            int t = Y*i - Y - (i-2)*(i-1)/2 + (j-i);
            int m = ll[t];
            for (int k=1; k<=i/2; k++)
                m = m >= ll[Y*k - Y - (k-2)*(k-1)/2 + (j-k)] + ll[Y*(i-k) - Y - (i-k-2)*(i-k-1)/2 + (j-(i-k))] ? m : ll[Y*k - Y - (k-2)*(k-1)/2 + (j-k)] + ll[Y*(i-k) - Y - (i-k-2)*(i-k-1)/2 + (j-(i-k))];
            for (int k=1; k<=j/2; k++) {
                if (i > k && i > j-k)
                    m = m >= ll[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + ll[Y*(j-k) - Y - (j-k-2)*(j-k-1)/2 + (i-(j-k))] ? m : ll[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + ll[Y*(j-k) - Y - (j-k-2)*(j-k-1)/2 + (i-(j-k))];
                else if (i > k)
                    m = m >= ll[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + ll[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)] ? m : ll[Y*k - Y - (k-2)*(k-1)/2 + (i-k)] + ll[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)];
                else
                    m = m >= ll[Y*i - Y - (i-2)*(i-1)/2 + (k-i)] + ll[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)] ? m : ll[Y*i - Y - (i-2)*(i-1)/2 + (k-i)] + ll[Y*i - Y - (i-2)*(i-1)/2 + (j-k-i)];
            }
            ll[t] = m;
        }
    }

    printf("%d\n", ll[T-1]);

    return 0;
}
