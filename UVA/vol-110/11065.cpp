#include <iostream>
#include <algorithm>
using namespace std;


typedef long long BSet;
BSet N[100];
int n, mx;
int bk(BSet R, BSet P, BSet X, int sz) {
    if (!P) {
        if (!X && sz>mx) mx = sz;
        return X ? 0 : 1;
    }

    bool f = 1;
    int result = 0;
    long long sv = 1, u=-1;
    for (int v=0; v<n; ++v, sv<<=1)
        if (P & sv & u) {
            if (f) {
                u = ~N[v];
                f = 0;
            }

            P &= ~sv;
            result += bk(R|sv, P&N[v], X&N[v], sz+1);
            X |= sv;
            if (!P) break;
        }
    return result;
}


int ord[100], deg[100], adj[100][100];
bool comp(int i, int j) { return deg[i] > deg[j]; }

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, m, u, v;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        BSet fl = (1LL<<n)-1;
        for (int i=0; i<n; ++i) {
            ord[i] = i;
            deg[i] = 0;
        }

        for (int i=0; i<m; ++i) {
            cin >> u >> v;
            adj[u][deg[u]++] = v;
            adj[v][deg[v]++] = u;
        }

        sort(ord, ord+n, comp);
        for (int i=0; i<n; ++i) {
            int u = ord[i];
            BSet Nu = fl;
            for (int j=0; j<deg[u]; ++j) {
                int v = adj[u][j];
                Nu &= ~(1LL << v);
            }
            N[u] = Nu;
        }

        cout << bk(0, fl, 0, mx=0) << endl;
        cout << mx << endl;
    }
}
