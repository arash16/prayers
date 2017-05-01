#include <bits/stdc++.h>
#define INF 268435456
#define EPS 1e-9
using namespace std;

void nearestToLine(
    double ax, double ay,
    double bx, double by,
    double px, double py,
    double &cpx, double &cpy ) {
    double proj = ( (px - ax) * (bx - ax) + (py - ay) * (by - ay) ) /
                  ( (bx - ax) * (bx - ax) + (by - ay) * (by - ay) );
    cpx = ax + proj * (bx - ax);
    cpy = ay + proj * (by - ay);
}

bool nearestToLineSegment(
    double ax, double ay,
    double bx, double by,
    double px, double py,
    double &cpx, double &cpy ) {
    if ( (bx - ax) * (px - ax) + (by - ay) * (py - ay) < EPS )
        return 0;

    if ( (ax - bx) * (px - bx) + (ay - by) * (py - by) < EPS )
        return 0;

    nearestToLine(ax, ay, bx, by, px, py, cpx, cpy);
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    vector<int> adj[55];
    int W[55][55], bn, cn, m, qn;
    double Cx[55], Cy[55], Bx[55], By[55], Px[55], Py[55];
    for (int cse=1; cin >> bn >> cn >> m >> qn && (bn||cn||m||qn); ++cse) {
        for (int i=0; i<bn; ++i)
            cin >> Bx[i] >> By[i];

        for (int i=0; i<cn; ++i) {
            cin >> Cx[i] >> Cy[i];
            for (int j=0; j<i; ++j)
                W[i][j] = W[j][i] = INF;
        }

        for (int u,v; m--; ) {
            cin >> u >> v; --u; --v;

            int sz = 2;
            Px[0] = Cx[u]; Py[0] = Cy[u];
            Px[1] = Cx[v]; Px[1] = Cy[v];
            for (int i=0; i<bn; ++i)
                if (nearestToLineSegment(Cx[u], Cy[u], Cx[v], Cy[v], Bx[i], By[i], Px[sz], Py[sz]))
                    ++sz;

            int cnt = 0;
            bool S[55] = {};
            for (int i=0; i<sz; ++i) {
                int ni=-1;
                double di = 1e100;
                for (int j=0; j<bn; ++j) {
                    double xx = Px[i]-Bx[j], yy = Py[i]-By[j];
                    double dd = xx*xx + yy*yy;
                    if (dd < di) {
                        di = dd;
                        ni = j;
                    }
                }
                if (ni!=-1 && !S[ni]) {
                    S[ni] = 1;
                    ++cnt;
                }
            }
            W[u][v] = W[v][u] = cnt-1;
        }

        for (int k=0; k<cn; ++k)
            for (int i=0; i<cn; ++i)
            if (i!=k && W[i][k]<INF)
                for (int j=0; j<cn; ++j)
                if (j!=k && W[k][j]<INF)
                    W[i][j] = min(W[i][j], W[i][k] + W[k][j]);

        cout << "Case " << cse << ":\n";
        for (int u,v; qn--; ) {
            cin >> u >> v; --u; --v;
            if (W[u][v] == INF)
                cout << "Impossible\n";
            else
                cout << W[u][v] << '\n';
        }
    }
}
