/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10054
  Name: The Necklace
  Problem: https://onlinejudge.org/external/100/10054.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

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

// -------------------------------------------------------------

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);


    vector<int> adj[55];
    int T = readUInt();
    for (int cse=1; cse<=T; ++cse) {
        int n = readUInt();

        if (cse > 1) cout << "\n";
        cout << "Case #" << cse << "\n";

        int E[55][55] = {};
        for (int i=1; i<=50; ++i)
            adj[i].clear();

        int mn = 100;
        for (int i=0; i<n; ++i) {
            int u = readUInt(),
                v = readUInt();
            adj[u].push_back(v);
            adj[v].push_back(u);
            ++E[u][v]; ++E[v][u];
            mn = min(mn, min(u, v));
        }

        bool bad=0;
        list<int> p;
        for (int u=1; u<=50; ++u)
            if (adj[u].size()&1) {
                bad = 1;
                break;
            }

        if (bad) cout << "some beads may be lost\n";
        else {
            p.push_back(mn);
            for (auto it=p.begin(); it!=p.end(); ++it)
                if (adj[*it].size()) {
                    auto it2 = it;
                    int u = *it2;
                    while (adj[u].size()) {
                        int v;
                        do {
                            if (adj[u].empty()) goto fin;
                            v = adj[u].back();
                            adj[u].pop_back();
                        } while (!E[u][v]);
                        --E[u][v]; --E[v][u];

                        it2 = p.insert(++it2, v);
                        u = v;
                    }
                    fin:;
                }

            int last = -1;
            for (int x: p) {
                if (last != -1)
                    cout << last << ' ' << x << "\n";
                last = x;
            }
        }
    }
}
