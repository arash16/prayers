#include <stdio.h>

int mat[30][30], sum[30], vv[30][2];
int main(){
    int T, n, m, x;
    scanf("%d", &T);
    for (int cse=1; cse<=T; ++cse) {
        int ced = 0;
        bool isvalid = 1;
        scanf("%d%d", &n, &m);
        for (int j=0; j<m; ++j) sum[j]=0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                scanf("%d", &x);
                if (x && isvalid) {
                    if (sum[j]==2) isvalid = 0;
                    else {
                        int *v = vv[j];
                        v[sum[j]++] = i;
                        if (sum[j] == 2) {
                            if (mat[v[0]][v[1]] == cse) isvalid = 0;
                            else mat[v[0]][v[1]] = mat[v[1]][v[0]] = cse;
                            ++ced;
                        }
                    }
                }
            }
        if (ced!=m) isvalid=0;
        puts(isvalid ? "Yes" : "No");
    }
}
