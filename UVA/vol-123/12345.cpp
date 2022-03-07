/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12345
  Name: Dynamic len(set(a[L:R]))
  Problem: https://onlinejudge.org/external/123/12345.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <bitset>
using namespace std;

int ids[1000001], icnt=1;
int getId(int x) {
    if (!ids[x])
        ids[x] = icnt++;
    return ids[x];
}

bool seen[100000];
int X[50001];
int main() {
    char mq;
    int n, m, l, r;
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &r);
        X[i] = getId(r);
    }
    for (int i=0; i<m; i++) {
        scanf(" %c %d %d", &mq, &l, &r);
        if (mq == 'Q') {
            memset(seen, 0, icnt);
            int cnt = 0;
            for (int i=l; i<r; i++) {
                int x = X[i];
                if (!seen[x]) {
                    seen[x] = 1;
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
        else X[l] = getId(r);
    }
}
