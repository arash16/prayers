/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10389
  Name: Subway
  Problem: https://onlinejudge.org/external/103/10389.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int n;
struct Point {
    int x, y;
    bool operator == (const Point& p) const { return x==p.x && y==p.y; }
} p[300];

double dist(int i, int j) {
    int xx = p[i].x-p[j].x,
        yy = p[i].y-p[j].y;

    return sqrt(xx*xx + yy*yy);
}


bool S[300][300], seen[300];
double M[300][300], D[300], H[300];

const double SS = 40000/60.0,
             WS = 10000/60.0;

int readPoint() {
    cin >> p[n].x >> p[n].y;
    if (p[n].x==-1 && p[n].y==-1)
        return -1;

    for (int i=0; i<n; ++i)
        if (p[i] == p[n])
            return i;

    for (int i=0; i<n; ++i) {
        M[i][n] = dist(i, n);
        S[i][n] = 0;
    }
    return n++;
}


struct UD {
    int u;
    double d;
    UD(int u, double d):u(u),d(d){ }
    bool operator < (const UD& ud) const { return d+H[u] > ud.d + H[ud.u]; }
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T; cin >> T;
    while (T--) {
        n = 0; readPoint();
        n = 1; readPoint();

        n = 2;
        while (cin.ignore(1000,'\n')) {
            if (cin.peek() == '\n') break;
            int lst = readPoint(), cur;
            while ((cur=readPoint()) != -1) {
                S[lst][cur] = S[cur][lst] = 1;
                lst = cur;
            }
        }


        for (int i=0; i<n; ++i) {
            H[i] = dist(i, 1) / SS;
            D[i] = 1e300;
            seen[i] = 0;
            for (int j=0; j<i; ++j)
                M[i][j] = M[j][i] = M[j][i] / (S[j][i] ? SS : WS);
        }


        priority_queue<UD> q;
        q.push(UD(0, D[0]=0));
        while (!q.empty()) {
            UD ud = q.top(); q.pop();
            int u = ud.u;
            if (u == 1) {
                cout << round(ud.d) << endl;
                break;
            }

            if (seen[u]) continue;
            seen[u] = 1;

            for (int v=0; v<n; ++v)
                if (u!=v && !seen[v]) {
                    UD vd(v, ud.d + M[u][v]);
                    if (vd.d < D[v]) {
                        D[v] = vd.d;
                        q.push(vd);
                    }
                }
        }
        if (T) cout << endl;
    }
}
