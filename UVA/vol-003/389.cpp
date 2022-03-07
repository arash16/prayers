/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 389
  Name: Basically Speaking
  Problem: https://onlinejudge.org/external/3/389.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

char num[10000], w[10];
int main(){
    int s, t;

    while (scanf("%s %d %d", num, &s, &t)==3) {
        bool err=0;
        int b10 = 0;
        int maxx = pow(t, 7) - 1;

        for (int i=0; !err && num[i]; i++) {
            int x = num[i]>='A' ? (10+num[i]-'A') : num[i]-'0';
            b10 = b10 * s + x;
            if (b10 > maxx) err=1;
        }

        if (err) puts("  ERROR");
        else if (!b10) puts("      0");
        else {
            int i=6;
            for(; b10; b10/=t) {
                int x = b10%t;
                w[i--] = x>9 ? ('A'+x-10) : ('0'+x);
            }
            while(i>=0) w[i--] = ' ';
            puts(w);
        }
    }
}
