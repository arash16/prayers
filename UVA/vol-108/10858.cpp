#include <math.h>
#include <stdio.h>


int cnt, outs[1000000][30], deg[1000000], nums[30];
void gen(int n, int mn, int len) {
    if (n == 1) {
        if (len>1) {
            for (int i=0; i<len; ++i)
                outs[cnt][i] = nums[i];
            deg[cnt++] = len;
        }
        return;
    }

    int sq = sqrt(n);
    for (int i=mn; i<=sq; ++i)
        if (n%i==0) {
            nums[len] = i;
            gen(n/i, i, len+1);
        }
    nums[len] = n;
    gen(1, n, len+1);
}


int main() {
    int n;
    while (scanf("%d",&n)==1 && n) {
        cnt = 0;
        gen(n, 2, 0);
        printf("%d\n", cnt);
        for (int i=0; i<cnt; ++i) {
            printf("%d", outs[i][0]);
            for (int j=1; j<deg[i]; ++j)
                printf(" %d", outs[i][j]);
            putchar('\n');
        }
    }
}
