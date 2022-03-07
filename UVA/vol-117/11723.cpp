/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11723
  Name: Numbering Roads
  Problem: https://onlinejudge.org/external/117/11723.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int cse=1, n, r;
    while (cin>>n>>r && (n||r)) {
        printf("Case %d: ", cse++);

        int x = ceil((double)n/r) - 1;
        if (x>26) puts("impossible");
        else cout<<x<<endl;
    }
}

