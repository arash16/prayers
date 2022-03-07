/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11369
  Name: Shopaholic
  Problem: https://onlinejudge.org/external/113/11369.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int X[20002];
int main(){
    int T, n;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=0; i<n; i++)
            cin>>X[i];
        sort(X, X+n);

        int sum = 0;
        for (int i=n%3; i<n; i+=3)
            sum += X[i];

        cout << sum << endl;
    }
}
