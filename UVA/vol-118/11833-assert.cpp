/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11833
  Name: Route Change
  Problem: https://onlinejudge.org/external/118/11833.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int S[343][343];
int main() {
    int n, m, c, k;
    for (int cse=1; cin>>n>>m>>c>>k && (n||m||c||k); ++cse) {
        bool f = false;
        for (int i=0, u,v,d; i<m; ++i) {
            cin >> u >> v >> d;
            if (S[u][v] == cse && !f) {
                cout << "Case " << cse << " has duplicate roads.\n";
                f = true;
            }
            else S[u][v] = S[v][u] = cse;
        }
    }
}
