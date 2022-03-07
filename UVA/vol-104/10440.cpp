/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10440
  Name: Ferry Loading II
  Problem: https://onlinejudge.org/external/104/10440.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, c, t, m, x[2000];
    cin>>T;
    while (T--) {
        cin>>c>>t>>m;
        for (int i=0; i<m; i++)
            cin>>x[i];

        int i, cnt, tm=-t, fr=m%c;
        if (fr) fr = c-fr;
        for (i=cnt=0; i<m; cnt++) {
            tm += t; // return of ferry

            int cu=0;
            while (cu<c && (x[i]<=tm || c-cu>fr)) {
                tm = max(tm, x[i]);
                cu++;
                i++;
            }

            fr -= c-cu;
            tm += t;
        }

        printf("%d %d\n", tm, cnt);
    }
}
