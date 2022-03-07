/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12527
  Name: Different Digits
  Problem: https://onlinejudge.org/external/125/12527.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int isLucky(int n) {
    int dis[4], dc=0;
    for (; n; n/=10) {
        int d = n%10;
        for (int i=0; i<dc; i++)
            if (dis[i] == d)
                return 0;
        dis[dc++] = d;
    }
    return 1;
}

int C[5005] = {1}, n, m;
int main() {
    for (int i=1; i<5005; i++)
        C[i] = C[i-1] + isLucky(i);
    while (scanf("%d%d", &n, &m)==2)
        printf("%d\n", C[m] - C[n-1]);
}
