#include <stdio.h>
#include <iostream>
using namespace std;

int n, m;
char X[500][500], Y[500][500], tmp[500][500];
void rotate() {
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
            tmp[i][j] = Y[m-j-1][i];
    swap(tmp, Y);
}

bool eqsq(int u, int v) {
    for (int i=0; i<m; ++i)
        for (int j=0; j<m; ++j)
            if (X[u+i][v+j] != Y[i][j])
                return false;
    return true;
}

int main() {
    while (scanf("%d%d", &n, &m)==2 && (n||m)) {
        for (int i=0; i<n; ++i)
            scanf("%s", X[i]);
        for (int i=0; i<m; ++i)
            scanf("%s", Y[i]);

        for (int k=0; k<4; ++k) {
            int cnt = 0;
            for (int i=0; i<=n-m; ++i)
                for (int j=0; j<=n-m; ++j)
                    if (eqsq(i, j))
                        ++cnt;

            printf("%d", cnt);
            if (k < 3) {
                putchar(' ');
                rotate();
            }
        }
        putchar('\n');
    }
}
