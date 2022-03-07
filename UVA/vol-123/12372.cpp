/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12372
  Name: Packing for Holiday
  Problem: https://onlinejudge.org/external/123/12372.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    for(int i=1; i<=n; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        printf("Case %d: %s\n", i, (a<=20 && b<=20 && c<=20) ? "good" : "bad");
    }
}
