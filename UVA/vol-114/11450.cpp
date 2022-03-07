/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11450
  Name: Wedding shopping
  Problem: https://onlinejudge.org/external/114/11450.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n;
vector<int> items[30];
int memo[202][22];
int ks(int remm, int ind) {
    if (ind==n) return 0;
    if (remm<=0) return -(1<<30);
    if (memo[remm][ind] != -1)
        return memo[remm][ind];

    int mx = -(1<<30);
    for (int w: items[ind])
        if (w <= remm)
            mx = max(mx, ks(remm-w, ind+1) + w);

    return memo[remm][ind] = mx;
}



int main(){
    int T, m, k, x;
    cin>>T;
    while (T--) {
        cin>>m>>n;
        int sm = 0;
        for (int i=0; i<n; i++) {
            cin >> k;
            int mn = 1<<30;
            items[i].clear();
            for (int j=0; j<k; j++) {
                cin >> x;
                items[i].push_back(x);
                if (x < mn) mn = x;
            }
            sm += mn;
        }

        if (sm > m) puts("no solution");
        else if (sm == m) cout << sm << endl;
        else {
            memset(memo, -1, sizeof(memo));
            cout << ks(m, 0) << endl;
        }
    }
}
