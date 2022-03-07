/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10700
  Name: Camel trading
  Problem: https://onlinejudge.org/external/107/10700.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    char line[200], op[20];
    int T, n, x[20];
    cin>>T;
    while(T--) {
        cin >> line;
        stringstream sin(line);

        sin>>x[n=0];
        while (sin>>op[++n])
            sin>>x[n];

        vector<long long> v1, v2;
        long long mx = x[0], mn = mx;
        for (int i=1; i<n; i++)
            if (op[i]=='+') {
                v2.push_back(mn);
                mx += x[i];
                mn = x[i];
            }
            else {
                v1.push_back(mx);
                mn *= x[i];
                mx = x[i];
            }

        for (long long y: v1) mx*=y;
        for (long long y: v2) mn+=y;

        printf("The maximum and minimum are %lld and %lld.\n", mx, mn);
    }
}
