/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11242
  Name: Tour de France
  Problem: https://onlinejudge.org/external/112/11242.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int f[1000], m, n, r;
    double dr[100000];
    while (scanf("%d%d", &m, &n)==2) {
        for (int i=0; i<m; i++)
            scanf("%d", f + i);

        int c = 0;
        for (int i=0; i<n; i++) {
            scanf("%d", &r);
            for (int j=0; j<m; j++)
                dr[c++] = (double)r / f[j];
        }

        double mx=0;
        sort(dr, dr+c);
        for (int i=1; i<c; i++)
            mx = max(mx, dr[i] / dr[i-1]);

        printf("%.2lf\n", mx);
    }
}
