/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12502
  Name: Three Families
  Problem: https://onlinejudge.org/external/125/12502.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, a, b, m;
    cin>>T;
    while(T--) {
        cin>>a>>b>>m;
        cout << (3*a*m)/(a+b)-m << endl;
    }
}
