/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11805
  Name: Bafana Bafana
  Problem: https://onlinejudge.org/external/118/11805.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int cse=1; cse<=t; cse++) {
        int n,k,p,r;
        cin>>n>>k>>p;
        r=(k+p)%n;
        printf("Case %d: %d\n", cse, r ? r : n);
    }
}
