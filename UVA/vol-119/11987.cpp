/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11987
  Name: Almost Union-Find
  Problem: https://onlinejudge.org/external/119/11987.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int P[200143], C[200143], S[200143], n, m;

int Find(int p) {
  return P[p]==p ? p : P[p] = Find(P[p]);
}

void Union(int p, int q) {
  if (Find(p) == Find(q)) return;
  C[Find(q)] += C[Find(p)];
  S[Find(q)] += S[Find(p)];
  P[Find(p)] = Find(q);
}

void Move(int p, int q) {
  if (Find(p) == Find(q)) return;
  C[Find(p)]--;
  S[Find(p)]-=p;
  C[Find(q)]++;
  S[Find(q)]+=p;
  P[p] = Find(q);
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  while (cin >> n >> m) {
    for (int i=1; i<=n; ++i) {
      P[i] = n+i;
      C[n+i] = 1;
      S[n+i] = i;
    }
    for (int i=n+1; i<=2*n; ++i) {
      P[i] = i;
    }

    for (int i=0; i<m; ++i) {
      int t, p, q; cin >> t;
      switch(t) {
        case 1:
          cin >> p >> q;
          Union(p, q);
          break;

        case 2:
          cin >> p >> q;
          Move(p, q); // move p to q
          break;

        case 3:
          cin >> p;
          cout << C[Find(p)] << ' ' << S[Find(p)] << endl;
      }
    }
  }
}
