#include <bits/stdc++.h>
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
inline bool readDouble(double &r) {
    char ch;
    int sgn=1;
    while (!isdigit(ch=readchar()) && ch!='-')
        if (ch == EOF)
            return 0;

    if (ch == '-') sgn = -1;
    else r = ch-'0';

    while (isdigit(ch=readchar()))
        r = r*10 + ch-'0';

    if (ch=='.') {
        double p = 1;
        while (isdigit(ch=readchar()))
            r += (ch-'0') * (p *= 0.1);
    }
    return 1;
}

// ---------------------------------------------------------------------------



int n, S[10043], cse=1;
double maxd, D[10043], E[10043];
struct Point {
    double x, y;
    bool operator < (const Point &p) const { return x < p.x; }
} P[10043];

double dist2(int i, int j) {
    double xx = P[i].x-P[j].x,
           yy = P[i].y-P[j].y;
    return xx*xx + yy*yy;
}

double est(int u) {
    if (S[u]!= cse) {
        S[u] = cse;
        E[u] = sqrt(dist2(u, n+1));
    }
    return E[u];
}

struct State {
    int u;
    double d, t;
    State(int u, double d):u(u),d(d),t(est(u)) { }
    bool operator < (const State &o) const { return d+t < o.d+o.t; }
};

inline bool checkPush(priority_queue<State> &q, double d, int u, int v) {
    double w = dist2(u, v);
    if (w <= 2.25) {
        double dd = d + sqrt(w);
        if (dd < D[v]) {
            State t(v, D[v]=dd);
            if (t.d + t.t <= maxd) {
                q.push(t);
                return 1;
            }
        }
    }
    return 0;
}


bool dijkstra() {
    for (int i=0; i<n+2; ++i)
        D[i] = 1e100;

    priority_queue<State> q;
    q.push(State(0, D[0]=0));
    while (!q.empty()) {
        State s = q.top(); q.pop();
        if (s.d > D[s.u]) continue;

        for (int v=s.u-1; v>=0 && P[s.u].x-P[v].x<=1.5; --v)
            if (checkPush(q, s.d, s.u, v) && v==n+1)
                return 1;

        for (int v=s.u+1; v<n+2 && P[v].x-P[s.u].x<=1.5; ++v)
            if (checkPush(q, s.d, s.u, v) && v==n+1)
                return 1;
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);

    double w, h;
    for (; readDouble(w) && readDouble(h); ++cse) {
        n = readUInt();
        for (int i=1; i<=n; ++i) {
            readDouble(P[i].x);
            readDouble(P[i].y);
        }
        P[n+1].x = w;
        P[n+1].y = h;
        sort (P+1, P+n+1);
        readDouble(maxd);

        cout << (dijkstra() ? "I am lucky!\n" : "Boom!\n");
    }
}
