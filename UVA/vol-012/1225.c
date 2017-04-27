#include <stdio.h>

int count[10005][10];
int main(){
    int i, j, k, T, n;
    int *r;

    for (i=1; i<10005; i++) {
        for (j=0; j<10; j++)
            count[i][j] = count[i-1][j];

        for (k=i; k; k/=10)
            count[i][k%10]++;
    }

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        r = count[n];
        printf("%d %d %d %d %d %d %d %d %d %d\n", r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9]);
    }
}
