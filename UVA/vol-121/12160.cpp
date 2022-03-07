/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12160
  Name: Unlock the Lock
  Problem: https://onlinejudge.org/external/121/12160.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);


    vector<int> X;
    int src, dst, n;
    for (int cse=1; cin >> src >> dst >> n && (src||dst||n); ++cse) {
        cout << "Case " << cse << ": ";

        X.resize(n);
        for (int i=0; i<n; ++i)
            cin >> X[i];

        if (src == dst)
            cout << 0 << endl;
        else {
            int d[10000]={};
            queue<int> q;
            q.push(src);
            d[src]=1;
            while (!q.empty()) {
                int c = q.front(); q.pop();
                for (int x: X) {
                    int nc = (c + x)%10000;
                    if (!d[nc]) {
                        if (nc == dst) {
                            cout << d[c] << endl;
                            goto fin;
                        }
                        d[nc] = d[c] + 1;
                        q.push(nc);
                    }
                }
            }
            cout << "Permanently Locked\n";
        }
        fin:;
    }
}
