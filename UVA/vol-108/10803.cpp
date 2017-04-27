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

// ------------------------------------------------------------------------

struct Point {
    int x, y;
    bool operator < (const Point &p) const { return x < p.x; }
} P[143]; int n;
vector<int> adj[143];
double W[143][143], D[143];

int dist2(int i, int j) {
    int xx = P[i].x - P[j].x,
        yy = P[i].y - P[j].y;
    return xx*xx + yy*yy;
}

struct State {
    int u; double d;
    State(int u, double d):u(u),d(d){}
    bool operator < (const State& o) const { return d > o.d; }
};

double dijkstra(int src) {
    for (int i=0; i<n; ++i) D[i] = 1e100;

    priority_queue<State> q;
    q.push(State(src, D[src]=0));
    while (!q.empty()) {
        State s = q.top(); q.pop();
        if (s.d != D[s.u]) continue;

        for (int v: adj[s.u]) {
            double d = s.d + W[s.u][v];
            if (d < D[v])
                q.push(State(v, D[v]=d));
        }
    }

    double mxd = D[0];
    for (int i=1; mxd<1e10 && i<n; ++i)
        mxd = max(mxd, D[i]);
    return mxd;
}


int main() {
    ios_base::sync_with_stdio(0);
    cout << fixed;

    int T = readUInt();
    for (int cse=1; cse<=T; ++cse) {
        cout << "Case #" << cse <<":\n";

        n = readUInt();
        for (int i=0; i<n; ++i) {
            P[i].x = readUInt();
            P[i].y = readUInt();
            adj[i].clear();
        }

        sort(P, P+n);
        for (int i=0; i<n; ++i)
            for (int j=i+1; j<n && P[j].x-P[i].x<=10; ++j) {
                int d2 = dist2(i, j);
                if (d2 <= 100) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    W[i][j] = W[j][i] = sqrt(double(d2));
                }
            }

        double mxd = dijkstra(0);
        if (mxd > 1e10) cout << "Send Kurdy\n\n";
        else {
            for (int i=1; i<n; ++i)
                mxd = max(mxd, dijkstra(i));

            cout << setprecision(4) << mxd << "\n\n";
        }
    }
}
