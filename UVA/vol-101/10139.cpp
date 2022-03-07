/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10139
  Name: Factovisors
  Problem: https://onlinejudge.org/external/101/10139.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

bool hase(int n, int f, int c) {
    int sum = 0;
    for (int ff=f; ff<=n; ff*=f) {
        sum += n/ff;
        if (sum >= c)
            return true;
    }

    return false;
}

bool check(int n, int m) {
    int sq = sqrt((double)m);
    for (int i=2; i<=sq; i++)
        if (m%i==0) {
            int cnt=0;
            do {
                cnt++;

                m /= i;
            } while (m%i==0);

            if (!hase(n, i, cnt))
                return false;

            sq = sqrt((double)m);
        }

    return m<=1 || n>=m;
}

int main(){
    int n, m;
    while (cin>>n>>m)
        if (check(n, m))
            printf("%d divides %d!\n", m, n);
        else
            printf("%d does not divide %d!\n", m, n);
}
