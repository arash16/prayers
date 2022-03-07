/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 306
  Name: Cipher
  Problem: https://onlinejudge.org/external/3/306.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;


#define MAXN 217

bool seen[MAXN];
int nxt[MAXN],
    cowner[MAXN], coffset[MAXN],
    cycles[MAXN][MAXN], cdeg[MAXN];

int main(){
    int n, k, x;

    while (scanf("%d", &n)==1 && n) {
        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            nxt[i] = x-1;
            seen[i] = 0;
        }

        int ccnt = 0;
        for (int i=0; i<n; ++i)
            if (!seen[i]) {
                int cid = ++ccnt;
                cdeg[cid] = 0;
                for (int j=i; !seen[j]; j=nxt[j]) {
                    seen[j] = 1;
                    cowner[j] = cid;
                    coffset[j] = cdeg[cid];
                    cycles[cid][cdeg[cid]++] = j;
                }
            }

        while (scanf("%d%*c", &k)==1 && k) {
            char str[MAXN], so[MAXN];
            cin.getline(str, MAXN);
            str[n] = 0;
            for (int i=strlen(str); i<n; ++i)
                str[i] = ' ';


            for (int i=0; i<n; ++i) {
                int cid = cowner[i],
                    ofs = (coffset[i] + k) % cdeg[cid];
                so[ cycles[cid][ofs] ] = str[i] ;
            }
            so[n] = 0;
            puts(so);
        }
        putchar('\n');
    }
}
