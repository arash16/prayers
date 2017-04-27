#include <stdio.h>
int S[1001][1001], x;
int main(){
    int frst=1, n, m;
    while (scanf("%d%d", &n, &m)==2) {
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++) {
                scanf("%d", &x);
                S[i][j] = x + S[i-1][j] + S[i][j-1] - S[i-1][j-1];
            }

        if (frst) frst = 0;
        else putchar('\n');

        long long totalSum = 0;
        for (int i=0; i<=n-m; i++)
            for (int j=0; j<=n-m; j++) {
                printf("%d\n", x = S[i+m][j+m] - S[i][j+m] - S[i+m][j] + S[i][j]);
                totalSum += x;
            }
        printf("%lld\n", totalSum);
    }
}
