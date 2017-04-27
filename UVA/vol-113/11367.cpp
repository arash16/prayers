#include <bits/stdc++.h>
#define INF 1073741824
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

// ------------------------------------------------------------------------

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

// ------------------------------------------------------------------------

struct State {
    int u, f, d;
    State(int u, int f, int d):u(u),f(f),d(d){}
};

vector<int>  adj[1043];
int cse, S[1043][1043],
         W[1043][1043],
         D[1043][100],
         E[1043][100],
         P[1043];

IndexQueue<State> q;
int dijkstra(int n, int mxc, int src, int dst) {
    q.clear();
    q.push(0, State(src, 0, D[src][0]=0));
    while (!q.empty()) {
        State s = q.pop();
        if (s.u == dst) return s.d;
        if (D[s.u][s.f] != s.d) continue;

        if (s.f < mxc) {
            int d = s.d + P[s.u];
            if (E[s.u][s.f+1]!=cse || d < D[s.u][s.f+1]) {
                E[s.u][s.f+1] =cse;
                q.push(d, State(s.u, s.f+1, D[s.u][s.f+1]=d));
            }
        }

        for (int v: adj[s.u]) {
            int w = W[s.u][v];
            if (s.f < w) break; // adj is sorted, so we can break out on first far city
            int r = s.f - w;
            if (E[v][r]!=cse || s.d < D[v][r]) {
                E[v][r] =cse;
                q.push(s.d, State(v, r, D[v][r]=s.d));
            }
        }
    }
    return -1;
}

int uuu;
bool comp(int v1, int v2) {
    return W[uuu][v1] < W[uuu][v2];
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    for (cse=1; (n=readUInt())!=EOF && (m=readUInt())!=EOF; ++cse) {
        for (int i=0; i<n; ++i) {
            P[i] = readUInt();
            adj[i].clear();
        }

        for (int i=0; i<m; ++i) {
            int u = readUInt(),
                v = readUInt(),
                d = readUInt();
            if (S[u][v] == cse)
                W[u][v] = W[v][u] = min(W[u][v], d);
            else {
                S[u][v] = S[v][u] = cse;
                W[u][v] = W[v][u] = d;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        for (uuu=0; uuu<n; ++uuu)
            sort(adj[uuu].begin(), adj[uuu].end(), comp);

        m = readUInt();
        for (; m--; ++cse) {
            int c = readUInt(),
                s = readUInt(),
                e = readUInt();
            int r = dijkstra(n, c, s, e);
            if (r < 0) cout << "impossible\n";
            else cout << r << endl;
        }
    }
}
