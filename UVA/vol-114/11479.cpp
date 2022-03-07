/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11479
  Name: Is this the easiest problem?
  Problem: https://onlinejudge.org/external/114/11479.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin>>T;
    for(int cse=1; cse<=T; cse++) {
        long long int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a, a+3);
        cout << "Case " << cse << ": ";
        if (a[0]+a[1] <= a[2])
            cout << "Invalid\n";
        else if (a[0]==a[1] && a[1]==a[2])
            cout << "Equilateral\n";
        else if (a[0]==a[1] || a[1]==a[2])
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
}
