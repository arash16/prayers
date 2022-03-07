/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10025
  Name: The ? 1 ? 2 ? ... ? n = k problem
  Problem: https://onlinejudge.org/external/100/10025.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 1073741824
#define MAXM 20000000

int memo[MAXM];
int find(int n) {
    if (n < MAXM) {
        if (memo[n]>0)
            return memo[n];
        memo[n] = INF;
    }

    int k = ceil((sqrt(8.0*n+1)-1)/2);
    for (;; k++) {
        int sm = (k*(k+1))>>1;
        int di = sm - n;
        if (!di) return k;
        if (!(di&1)) {
            int dh = di>>1;
            if (dh<=k || find(dh)<=k) {
                if (n < MAXM)
                    memo[n]=k;
                return k;
            }
        }
    }
    return INF;
}


int main(){
    int T, n;
    cin>>T;
    while (T--) {
        cin >> n;
        if (n<0) n=-n;
        if (!n) puts("3");
        else if (n==1) puts("1");
        else cout << find(n) << endl;
        if (T) cout << endl;
    }
}
