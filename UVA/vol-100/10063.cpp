/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10063
  Name: Knuth's Permutation
  Problem: https://onlinejudge.org/external/100/10063.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


char S[17], P[17], n;
void dfs(int idx) {
    if (idx == n) {
        puts(P);
        return;
    }

    for (int i=idx; i>0; --i)
        P[i] = P[i-1];

    for (int i=0; i<=idx; ++i) {
        P[i] = S[idx];
        dfs(idx + 1);
        P[i] = P[i+1];
    }
}

int main() {
    bool frst = 1;
    while (cin.getline(S, 17)) {
        if (frst) frst = 0;
        else puts("");

        P[ n=strlen(S) ] = 0;
        dfs(0);
    }
}
