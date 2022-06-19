/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11090
  Name: Going in Cycle!!
  Problem: https://onlinejudge.org/external/110/11090.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;
#define oo 0xfffffff

int W[64][64], dist[64][64], n, m;
vector<int> E[64];
bool seen[64][64];

double spfa(int st) {
  for (int i=1; i<=n; ++i) {
    for (int l=0; l<=n; ++l) {
      dist[i][l] = oo;
      seen[i][l] = false;
    }
  }

  dist[st][0] = 0;
  queue<pair<int, int> > Q;
  Q.push(make_pair(st, 0));

  while (!Q.empty()) {
    auto p = Q.front(); Q.pop();
    int u = p.first, l = p.second;
    seen[u][l] = false;
    for (int v: E[u]) {
      if (dist[v][l+1] > dist[u][l] + W[u][v]) {
        dist[v][l+1] = dist[u][l] + W[u][v];
        if (!seen[v][l+1]) {
          seen[v][l+1] = true;
          Q.push(make_pair(v, l+1));
        }
      }
    }
  }

  double res = 1e9;
  for (int l=1; l<=n; ++l) {
    if (dist[st][l] != oo) {
      res = min(res, double(dist[st][l])/l);
    }
  }
  return res;
}


int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T; cin >> T;
  for (int cse=1; cse<=T; ++cse) {
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
      E[i].clear();
      for (int j=1; j<=n; ++j) {
        W[i][j] = oo;
      }
    }

    for (int i=0; i<m; ++i) {
      int p, q, w;
      cin >> p >> q >> w;
      E[p].push_back(q);
      W[p][q] = min(W[p][q], w);
    }

    double res = 1e9;
    for (int i=1; i<=n; ++i) {
      res = min(res, spfa(i));
    }

    printf("Case #%d: ", cse);
    if (res < 1e9) {
      printf("%.2lf\n", res);
    } else {
      printf("No cycle found.\n");
    }
  }
}
