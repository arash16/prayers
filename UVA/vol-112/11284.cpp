#include <math.h>
#include <stdio.h>
#include <list>
using namespace std;

#define INF 1073741824
int cse=1, mat[100][100], ope[100], ids[100], d[100][100], dn;
int memoid[8193][13],
    memo[8193][13];

int rec(int remp, int u) {
    if (memoid[remp][u] == cse)
        return memo[remp][u];

    int best = -d[u][0];
    if (remp) {
        int bit = 1;
        for (int v=0; v<=dn; v++, bit<<=1)
            if (remp & bit)
                best = max(best, rec(remp&(~bit), v) - d[u][v]);
    }

    memoid[remp][u] = cse;
    return memo[remp][u] = ope[ids[u]]+best;
}



int main(){
    double w;
    int T, n, m, p, u, v;
    scanf("%d", &T);
    for (cse=1; cse<=T; cse++) {
        scanf("%d%d", &n, &m);
        for (int i=0; i<=n; i++) {
            mat[i][i] = ope[i] = 0;
            for (int j=i+1; j<=n; j++)
                mat[i][j] = mat[j][i] = INF;
        }

        for (int i=0; i<m; i++) {
            scanf("%d%d%lf", &u, &v, &w);
            mat[u][v] = mat[v][u] = min(mat[u][v], (int)round(w*100));
        }

        // Floyd-Warshall
        for (int k=0; k<=n; k++)
            for (int i=0; i<=n; i++)
                if (mat[i][k] < INF)
                for (int j=0; j<=n; j++)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

        scanf("%d", &p);
        for (int i=0; i<p; i++) {
            scanf("%d%lf", &u, &w);
            ope[u] += round(w*100);
        }

        // New Graph with only Opera Sellers
        dn = 1;
        for (int i=1; i<=n; i++)
            if (ope[i]) {
                for (int j=0; j<dn; j++)
                    d[dn][j]=d[j][dn]= mat[i][ids[j]];
                ids[dn++] = i;
            }

        int result = rec((1<<dn)-2, 0);
        if (result <= 0)
             puts("Don't leave the house");
        else printf("Daniel can save $%d.%02d\n", result/100, result%100);
    }
}
