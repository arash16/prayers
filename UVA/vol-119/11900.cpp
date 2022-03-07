/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11900
  Name: Boiled Eggs
  Problem: https://onlinejudge.org/external/119/11900.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int n, p, q, w[32];
int memo[32][32];
int ks(int remw, int ind) {
    if (remw < 0) return -1;
    if (ind==n || !remw) return 0;
    if (memo[remw][ind] != -1)
        return memo[remw][ind];

    return memo[remw][ind] = max(ks(remw-w[ind], ind+1)+1, ks(remw, ind+1));
}

int main(){
    int T;
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin >> n >> p >> q;
        for (int i=0; i<n; i++)
            cin >> w[i];

        memset(memo, -1, sizeof(memo));
        printf("Case %d: %d\n", cse, min(p, ks(q, 0)));
    }
}
