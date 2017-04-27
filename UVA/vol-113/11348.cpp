#include <stdio.h>
#include <cstring>

int main(){
    int T, n, c, x, un[60], seen[10001];
    scanf("%d", &T);
    for (int cse=1; cse<=T; ++cse) {
        printf("Case %d:", cse);
        memset(seen, 0, sizeof(seen));

        int tn = 0;
        scanf("%d", &n);
        for (int i=0; i<n; ++i) {
            scanf("%d", &c);
            un[i] = 0;
            for (int j=0; j<c; ++j) {
                scanf("%d", &x);
                if (!seen[x]) {
                    ++un[i]; ++tn;
                    seen[x] = i + 1;
                }
                else if (seen[x]>0 && seen[x]!=i+1) {
                    --un[seen[x] - 1]; --tn;
                    seen[x] = -1;
                }
            }
        }

        if (!tn) putchar(' ');
        else for (int i=0; i<n; ++i)
            printf(" %.6lf%%", 100.0 * un[i] / (double)tn);
        putchar('\n');
    }
}
