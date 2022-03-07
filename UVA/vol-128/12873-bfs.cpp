/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12873
  Name: The Programmers
  Problem: https://onlinejudge.org/external/128/12873.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int P[501], C[23], match[501], S[501], sse;
bool PS[501][23];
vector<int> adjP[501], adjS[23];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, p, s, c, m;
    cin >> T;
    while (T--) {
        cin >> p >> s >> c >> m;
        memset(match, -1, p*sizeof(int));
        for (int i=0; i<p; ++i) {
            memset(PS[i], 0, s);
            adjP[i].clear();
        }

        memset(C, 0, s*sizeof(int));
        for (int i=0; i<s; ++i)
            adjS[i].clear();

        while (m--) {
            int pi, si;
            cin >> pi >> si;
            adjP[pi-1].push_back(si-1);
            adjS[si-1].push_back(pi-1);
            PS[pi-1][si-1] = 1;
        }

        int result = 0;
        for (int pi=0; pi<p; ++pi) {
            bool S[21] = {};
            queue<int> q;
            q.push(pi);
            while (!q.empty()) {
                int pi = q.front(); q.pop();
                for (int si: adjP[pi])
                    if (PS[pi][si] && !S[si]) {
                        S[si] = 1;
                        if (C[si] < c) {
                            for (int pp=pi, ss=si; ;pp=P[pp]) {
                                int s0 = match[pp];
                                match[pp] = ss;
                                PS[pp][ss] = 0;
                                if (s0 == -1) break;
                                PS[pp][ss=s0] = 1;
                            }
                            ++C[si];
                            ++result;
                            goto fin;
                        }
                        else {
                            for (int pi2: adjS[si])
                                if (!PS[pi2][si]) {
                                    P[pi2] = pi;
                                    q.push(pi2);
                                }
                        }
                    }
            }
            fin:;
        }
        cout << result << "\n";
    }
}
