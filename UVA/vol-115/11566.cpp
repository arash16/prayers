/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11566
  Name: Let's Yum Cha!
  Problem: https://onlinejudge.org/external/115/11566.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 268435456
using namespace std;


int P[107], V[107], DP[107][23][1005], M[107][23][1005], cse, a1, a2;
int rec(int id, int c, int r) {
    int aa = a2 - ceil(1.1L * (r + a1));
    if (c<0 || aa<0) return -INF;
    if (!c || !aa || id<0) return 0;
    if (M[id][c][r] == cse) return DP[id][c][r];

    DP[id][c][r] = max(
        rec(id-1, c, r),
        max(
            rec(id-1, c-1, r+P[id]) + V[id],
            rec(id-1, c-2, r+2*P[id]) + 2*V[id]
        )
    );
    M[id][c][r] = cse;
    return DP[id][c][r];
}

int main() {
    int n, x, t, k;
    for (cse=1; scanf("%d%d%d%d", &n, &x, &t, &k)==4 && (n++||x||t||k); ++cse) {
        a1 = t*n; a2 = x*n;

        for (int i=0; i<k; ++i) {
            scanf("%d", P+i);
            V[i] = 0;
            for (int j=0, iv; j<n; ++j)
                scanf("%d", &iv),
                V[i] += iv;
        }

        printf("%.2lf\n", double(rec(k-1, 2*n, 0))/n);
    }
}
