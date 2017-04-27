#include <bits/stdc++.h>
using namespace std;

void remove(vector<int> &v, int x) {
    int sz = 0;
    for (int i=0; i<v.size(); ++i)
        if (v[i] != x)
            v[sz++] = v[i];
    v.resize(sz);
}


struct Edge {
    int u, d;
    Edge(int u, int d):u(u),d(d){}
};


vector<int> adj[2543];

bool inside[2543];
Edge dfsDia(int u) {
    inside[u] = true;
    Edge r(u, 0);
    for (int v: adj[u])
        if (!inside[v]) {
            Edge rr = dfsDia(v);
            if (++rr.d > r.d)
                r = rr;
        }
    inside[u] = false;
    return r;
}


int P[2543], D[2543];
int dfsPath(int u, int dst, int d=0) {
    P[d] = u;
    if (u == dst) return d;
    inside[u] = true;
    for (int v: adj[u])
        if (!inside[v]) {
            int r = dfsPath(v, dst, d+1);
            if (r != -1) {
                inside[u] = false;
                return r;
            }
        }

    inside[u] = false;
    return -1;
}

int findDiameter(int t) {
    int u = dfsDia(t).u,
        v = dfsDia(u).u;

    //if (u > v) swap(u, v);
    return dfsPath(u, v) + 1;
}


struct Result {
    int i1, j1, i2, j2, l;
    Result(int i1, int j1, int i2, int j2, int l):i1(i1),j1(j1),i2(i2),j2(j2),l(l){}
    bool operator < (const Result& o) const { return l < o.l; }
};

Result calc(int root) {
    int i1 = D[root+0],
        j1 = D[root+1];

    remove(adj[i1], j1);
    remove(adj[j1], i1);

    int i2 = P[findDiameter(i1)>>1],
        j2 = P[findDiameter(j1)>>1];

    adj[i2].push_back(j2);
    adj[j2].push_back(i2);

    int l = findDiameter(0)-1;

    adj[i2].pop_back();
    adj[j2].pop_back();
    adj[i1].push_back(j1);
    adj[j1].push_back(i1);

    return Result(i1, j1, i2, j2, l);
}


char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            adj[i].clear();

        for (int i=1, u,v; i<n; ++i) {
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }

        int l = findDiameter(0);
        memcpy(D, P, sizeof(D));
        Result r(0,0,0,0,10000);
        for (int i=-2; i<2; ++i) {
            int root = (l>>1)+i;
            if (root>=0 && root+1<l) {
                Result r2 = calc(root);
                if (r2 < r) r = r2;
            }
        }

        cout    << r.l << endl
                << r.i1+1 << ' ' << r.j1+1 << endl
                << r.i2+1 << ' ' << r.j2+1 << endl;
    }
}
