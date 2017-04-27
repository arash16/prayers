#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

inline char readchar() {
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
inline int readInt() {
    char ch;
    unsigned int r=0;
    while (!isdigit(ch=readchar()))
        if (ch == EOF)
            return EOF;

    r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';

    // skip trailing precision/etc
    while (ch!=' ' && ch!='\n')
        ch = readchar();

    return r;
}

// -----------------------------------------------------------------

int par[10017];
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

// ---------------------------------------

#define MAXD 1007
struct Pair {
    int u, v;
    Pair(int u, int v):u(u),v(v){}
};

int maxd, mind;
vector<Pair> adj[MAXD];
void qClear() { maxd = 0; mind = MAXD; }
bool qEmpty() { return maxd<mind; }
void qPush(int u, int v, int d) {
    if (d>=MAXD || d<0) while(1);

    adj[d].push_back(Pair(u, v));
    if (d < mind) mind = d;
    if (d > maxd) maxd = d;
}
int qPop(int &u, int &v) {
    Pair &p = adj[maxd].back();
    u = p.u; v = p.v;
    int d = maxd;

    adj[maxd].pop_back();
    while (!qEmpty() && adj[maxd].empty())
        --maxd;

    return d;
}

// ---------------------------------------

int main() {
    int T = readInt();
    while (T--) {
        int n = readInt(),
            m = readInt();

        qClear();
        memset(par, -1, n*sizeof(int));
        for (int i=0; i<m; ++i) {
            int u = readInt()-1,
                v = readInt()-1,
                d = readInt();
            qPush(u, v, d);
        }

        int sum = 0;
        for (int cnt=1; cnt<n && !qEmpty(); ) {
            int u, v, d = qPop(u, v);
            if (join(u, v)) ++cnt;
            else sum += d;
        }

        for (int i=mind; i<=maxd; ++i) {
            sum += i*adj[i].size();
            adj[i].clear();
        }
        printf("%d\n", sum);
    }
}
