/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13109
  Name: Elephants
  Problem: https://onlinejudge.org/external/131/13109.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main(){
    int T, n, m, w, c;
    scanf("%d", &T);
    while (T--) {
        priority_queue<int, vector<int>, greater<int> > q;
        scanf("%d%d", &n, &m);

        for (int i=0; i<n; i++) {
            scanf("%d", &w);
            q.push(w);
        }

        for (c=0; !q.empty(); q.pop()) {
            m -= q.top();
            if (m >= 0) c++;
            else break;
        }

        printf("%d\n", c);
    }
}
