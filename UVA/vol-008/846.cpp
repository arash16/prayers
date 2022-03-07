/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 846
  Name: Steps
  Problem: https://onlinejudge.org/external/8/846.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, a, b;
    cin>>T;
    while(T--) {
        cin>>a>>b;
        int n = b-a,
            k = (sqrt(4.0*n+1)-1)/2,
            d = n - k*k - k;

        if (d == 0) cout << 2*k <<endl;
        else cout << 2*k + (d<=k+1 ? 1 : 2) << endl;
    }
}
