/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1226
  Name: Numerical surprises
  Problem: https://onlinejudge.org/external/12/1226.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, n;
    char s[3000];
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n, s);
        int r = 0;
        for (int i=0; s[i]; i++)
            r = (r*10 + s[i] - '0') % n;

        printf("%d\n", r);
    }
}
