/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10565
  Name: Matrix
  Problem: https://onlinejudge.org/external/105/10565.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, n, x, t;
    cin>>T;
    while (T--) {
        cin>>n;
        x = 0;
        for (int i=0; i<n; i++) {
            cin>>t;
            if (t) x = t;
        }

        if (!x) puts("-1");
        else {
            puts("2");
            printf("%d 0\n0 %d\n", -x, -x);
        }
    }
}
