/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12157
  Name: Tariff Plan
  Problem: https://onlinejudge.org/external/121/12157.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, n, x;
    cin>>T;
    for (int cse=1; cse<=T; cse++) {
        cin>>n;

        int m=0, j=0;
        for (int i=0; i<n; i++) {
            cin>>x;
            m += ((x/30) + 1) * 10;
            j += ((x/60) + 1) * 15;
        }

        printf("Case %d: ", cse);
        if (m<=j) cout << "Mile ";
        if (j<=m) cout << "Juice ";
        cout << (m<j ? m : j) << endl;
    }
}
