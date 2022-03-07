/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11222
  Name: Only I did it!
  Problem: https://onlinejudge.org/external/112/11222.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;

typedef bitset<10001> Bitset;

int main(){
    int T, n, p;
    scanf("%d", &T);
    for (int cse=1; cse<=T; cse++) {
        printf("Case #%d:\n", cse);

        Bitset bs[3];
        vector<int> probs[3];

        for (int i=0; i<3; i++) {
            scanf("%d", &n);
            for (int j=0; j<n; j++) {
                scanf("%d", &p);
                if (!bs[i][p]) {
                    probs[i].push_back(p);
                    bs[i].set(p);
                }
            }
        }
        Bitset    nbs0 = ~bs[0],
                nbs1 = ~bs[1],
                nbs2 = ~bs[2];
        bs[0] &= nbs1; bs[0] &= nbs2;
        bs[1] &= nbs0; bs[1] &= nbs2;
        bs[2] &= nbs0; bs[2] &= nbs1;

        int bsz[3];
        for (int i=0; i<3; i++)
            bsz[i] = bs[i].count();

        int mx = max(bsz[0], max(bsz[1], bsz[2]));
        for (int i=0; i<3; i++)
            if (bsz[i] == mx) {
                printf("%d %d", i+1, mx);
                sort(probs[i].begin(), probs[i].end());
                for (int p: probs[i])
                    if (bs[i][p])
                        printf(" %d", p);
                putchar('\n');
            }
    }
}
