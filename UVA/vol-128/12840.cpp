/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12840
  Name: The Archery Puzzle
  Problem: https://onlinejudge.org/external/128/12840.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int T; cin >> T;
  for (int cse=1; cse<=T; ++cse) {
    int X[73], n, s;
    cin >> n >> s;
    for (int i=0; i<n; ++i) {
      cin >> X[i];
    }

    sort(X, X+n, greater<int>());
    cout << "Case " << cse << ": ";

    bool done = false;
    queue<pair<int, vector<int> > > st;
    st.push(make_pair(0, vector<int>()));
    while (!st.empty()) {
      auto p = st.front(); st.pop();
      if (p.first == s) {
        cout << "[" << p.second.size() << "]";
        for (int i: p.second) {
          cout << ' ' << X[i];
        }
        cout << endl;
        done = true;
        break;
      }

      int last = p.second.size() ? p.second.back() : 0;
      for (int i=last; i<n; ++i) {
        if (p.first+X[i] <= s) {
          vector<int> sss(p.second);
          sss.push_back(i);
          st.push(make_pair(p.first+X[i], sss));
        }
      }
    }

    if (!done) {
      cout << "impossible" << endl;
    }
  }
}
