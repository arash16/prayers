/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1064
  Name: Network
  Problem: https://onlinejudge.org/external/10/1064.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


struct Packet {
    int st, ed;
    Packet(int a, int b):st(a),ed(b){}
    bool operator < (const Packet &o) const { return st > o.st; }
};


int O[7], Ml[7], Pi[1024], Ps[1024], Pe[1024], n, m, bsum;
int calcSize() {
    priority_queue<Packet> pp[7];
    int wl[7]={}, clen=0, mxlen = 0;

    for (int j=0, i=0; j<m; ++j) {
        int id = O[j];
        priority_queue<Packet> &q = pp[id];

        while (!q.empty() && wl[id]==q.top().st) {
            wl[id] = q.top().ed;
            clen -= q.top().ed - q.top().st;
            q.pop();
        }

        for (; wl[id]!=Ml[id]; ++i)
            if (Pi[i]==id && Ps[i]==wl[id]) {
                wl[id] = Pe[i];
                while (!q.empty() && wl[id]==q.top().st) {
                    wl[id] = q.top().ed;
                    clen -= q.top().ed - q.top().st;
                    q.pop();
                }
            }
            else {
                pp[Pi[i]].push(Packet(Ps[i], Pe[i]));
                clen += Pe[i] - Ps[i];
                mxlen = max(mxlen, clen);
            }
    }
    return mxlen;
}

bool used[7];
void bt(int idx) {
    if (idx == m) {
        bsum = min(bsum, calcSize());
        return;
    }

    for (int i=0; i<m; ++i)
        if (!used[i]) {
            used[i] = 1;
            O[idx] = i;
            bt(idx+1);
            used[i] = 0;
        }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> m >> n && (m||n); ++cse) {
        for (int i=0; i<m; ++i)
            cin >> Ml[i];

        for (int i=0; i<n; ++i) {
            cin >> Pi[i] >> Ps[i] >> Pe[i];
            --Pi[i]; --Ps[i];
        }

        bsum = (int) 1e9; bt(0);
        cout << "Case " << cse << ": " << bsum << "\n\n";
    }
}
