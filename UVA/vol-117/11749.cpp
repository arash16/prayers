#include <stdio.h>

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
int readInt() {
    int sgn=1;
    int r=0;
    char ch;
    while (!isdigit(ch=getchar()) && ch!='-');
    if (ch == '-') sgn = -1;
    else r = ch-'0';

    while (isdigit(ch=getchar()))
        r = r*10 + ch-'0';
    return sgn*r;
}


#define MAXE 1000001
int U[MAXE], V[MAXE], gid[600], gcn[600];
int find(int u) { return gid[u]==u ? u : gid[u]=find(gid[u]); }


int main(){
    int n, m, u, v, d;
    while (scanf("%d%d", &n, &m)==2 && (n||m)) {
        for (int i=0; i<n; ++i) {
            gid[i] = i;
            gcn[i] = 1;
        }

        int j = 0, mx = -2147483648;
        for (int i=0; i<m; ++i) {
            u = readInt();
            v = readInt();
            d = readInt();
            if (d > mx) {
                mx = d;
                j = 0;
            }
            if (d == mx) {
                U[j] = u - 1;
                V[j] = v - 1;
                ++j;
            }
        }

        int bcnt = 0;
        for (int k=0; k<j; ++k) {
            int ug = find(U[k]),
                vg = find(V[k]);

            if (ug != vg) {
                gid[ug] = vg;
                gcn[vg] += gcn[ug];
                if (gcn[vg] > bcnt) {
                    bcnt = gcn[vg];
                    if (bcnt == n) break;
                }
            }
        }

        printf("%d\n", bcnt);
    }
}
