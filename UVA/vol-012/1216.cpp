/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1216
  Name: The Bug Sensor Problem
  Problem: https://onlinejudge.org/external/12/1216.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int par[1000000];
int find(int u) { return par[u]<0 ? u : par[u]=find(par[u]); }
bool join(int u, int v) {
    if ((u=find(u)) != (v=find(v))) {
        if (par[v] < par[u])
            swap(u, v);

        par[u] += par[v];
        par[v] = u;
        return 1;
    }
    return 0;
}

// -----------------------------------------------------

#define INF 9223372036854775807
typedef long long Int;

int np;
struct Point {
    int x, y;
    bool operator < (const Point &p) const { return x!=p.x ? x<p.x : y<p.y; }
}
P[1001];
bool lessY(int i, int j) { return P[i].y < P[j].y; }

struct Edge {
    int u, v;
    Int d;
    Edge(int u, int v):u(u),v(v) {
        Int xx = P[u].x - P[v].x,
            yy = P[u].y - P[v].y;
        d = xx*xx + yy*yy;
    }
    bool operator < (const Edge &e) const { return d < e.d; }
};
vector<Edge> E;

Int cp(int s, int e) {
    int sz = e-s;
    if (sz <= 1) return INF;
    if (sz == 2) {
        Edge e(s, s+1);
        E.push_back(e);
        return e.d;
    }

    int mid = (s+e)>>1;
    Int del = min(cp(s, mid), cp(mid, e)),
        x1 = P[mid-1].x,
        x2 = P[mid].x;

    //TODO: understand the relation between delta and needed distanct points
    // 42 is the smallest number giving AC
    for (int i=mid-1; i>=s && x1-P[i].x <= 43*del; --i)
        for (int j=mid; j<e && P[j].x-x2 <= 43*del; ++j) {
            Edge e(i, j);
            E.push_back(e);
            if (e.d < del) del = e.d;
        }

    return del;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int k; cin>>k;
        E.clear();

        for (np=0; cin>>P[np].x && P[np].x!=-1; ++np)
            cin >> P[np].y;

        sort(P, P+np);
        cp(0, np);

        Int md;
        sort(E.begin(), E.end());
        memset(par, -1, np*sizeof(int));
        for (int i=0, cnt=k; cnt<np; ++i)
            if (join(E[i].u, E[i].v)) {
                md = E[i].d;
                ++cnt;
            }

        cout << ceil(sqrt(md)) << endl;
    }
}
