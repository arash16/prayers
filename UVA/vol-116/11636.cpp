/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11636
  Name: Hello World!
  Problem: https://onlinejudge.org/external/116/11636.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    for(int cse=1; cin>>n && n>=0; cse++)
        printf("Case %d: %d\n", cse, !n ? 0 : int(ceil(log2(n))));
}

