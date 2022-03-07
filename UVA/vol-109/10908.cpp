/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10908
  Name: Largest Square
  Problem: https://onlinejudge.org/external/109/10908.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

unsigned char X[200][200], ch;
int LM[200][200], RM[200][200], TM[200][200], BM[200][200];
int ru[200];


int main(){
    int T, m, n, q;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &m, &n, &q);
        printf("%d %d %d\n", m, n, q);

        for (int j=0; j<=n; j++) ru[j]=0;
        for (int i=0; i<=m; i++) {
            if (i<m) while (getchar()!='\n');

            int lj = 0;
            for (int j=0; j<=n; j++) {
                ch = X[i][j] = i<m && j<n ? getchar() : 0;

                if (ch != X[i][lj]) {
                    for (int k=lj; k<j; k++)
                        RM[i][k] = j-1;
                    lj = j;
                }
                LM[i][j] = lj;

                if (ch != X[ru[j]][j]) {
                    for (int k=ru[j]; k<i; k++)
                        BM[k][j] = i-1;
                    ru[j] = i;
                }
                TM[i][j] = ru[j];
            }
        }

        for (int r, c, i=0; i<q; i++) {
            scanf("%d%d", &r, &c);
            int d = min(c-LM[r][c], RM[r][c]-c);
            for (int i=0; i<=d; i++) {
                d=min(d, min(r-TM[r][c-i], BM[r][c-i]-r));
                d=min(d, min(r-TM[r][c+i], BM[r][c+i]-r));
                if (d < i) {
                    d = i-1;
                    break;
                }
            }
            printf("%d\n", 2*d+1);
        }
    }
}
