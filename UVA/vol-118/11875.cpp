/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11875
  Name: Brick Game
  Problem: https://onlinejudge.org/external/118/11875.pdf
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
        int n, x;
        cin>>n;
        for (int i=0; i<=n/2; i++)
            cin>>x;
        printf("Case %d: %d\n", cse, x);
        for (int i=0; i<n/2; i++)
            cin>>x;
    }
}
