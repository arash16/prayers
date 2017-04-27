#include <bits/stdc++.h>
#define INF 134217728
using namespace std;
inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
            fin = 1;
            return EOF;
        }
        p = buf;
    }
    return *p++;
}

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
    char ch;
    unsigned int r=0;
    while (!isdigit(ch=readchar()))
        if (ch == EOF) return EOF;
    r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';

    while (ch!=' ' && ch!='\n')
        ch = readchar();
    return r;
}

// ----------------------------------------------------------------------

template<class T>
class IndexQueue {
    int mind, maxd;
    vector<T> V[300000];
    void _update() {
        while (mind<=maxd && V[mind].empty()) ++mind;
        if (mind>maxd) clear();
    }

    public:
    IndexQueue() { mind=INF; maxd=-1; }
    bool empty() { _update(); return mind>maxd; }
    void clear() {
        for (int i=mind; i<=maxd; ++i)
            V[i].clear();
        mind=INF;
        maxd=-1;
    }

    void push(int key, T data) {
        V[key].push_back(data);
        if (key < mind) mind = key;
        if (key > maxd) maxd = key;
    }

    T pop() {
        _update();
        T r = V[mind].back();
        V[mind].pop_back();
        return r;
    }
};

// ----------------------------------------------------------------------

struct UD {
    int u, d;
    UD(int u, int d):u(u),d(d){}
};

IndexQueue<UD> q;
void dijkstra(int n, int src, int maxd, int D[], const vector<UD> adj[]) {
    for (int i=0; i<n; ++i)
        D[i] = INF;

    q.clear();
    q.push(0, UD(src, D[src]=0));
    while (!q.empty()) {
        UD ud = q.pop();
        int u = ud.u;
        if (ud.d != D[u]) continue;

        for (const UD &uv: adj[u]) {
            int d = ud.d + uv.d,
                v = uv.u;
            if (d <= maxd && d < D[v])
                q.push(d, UD(v, D[v]=d));
        }
    }
}


int DS[10043], DT[10043];
vector<UD> adj[10043], adr[10043];
int solve(int n, int src, int dst, int maxd) {
    dijkstra(n, src, maxd, DS, adj);
    if (DS[dst] > maxd) return -1;

    dijkstra(n, dst, maxd, DT, adr);
    if (DT[src] > maxd) return -1;

    int mxr = -1;
    for (int u=0; u<n; ++u)
        for (UD &vd: adj[u])
            if (vd.d > mxr) {
                int c = DS[u] + vd.d + DT[vd.u];
                if (c <= maxd)
                    mxr = vd.d;
            }
    return mxr;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    while (T--) {
        int n = readUInt(),
            m = readUInt(),
            src = readUInt()-1,
            dst = readUInt()-1,
            maxd = readUInt();

        for (int i=0; i<n; ++i) {
            adj[i].clear();
            adr[i].clear();
        }

        for (int i=0; i<m; ++i) {
            int u = readUInt() - 1,
                v = readUInt() - 1,
                d = readUInt();

            adj[u].push_back(UD(v, d));
            adr[v].push_back(UD(u, d));
        }

        cout << solve(n, src, dst, maxd) << endl;
    }
}
