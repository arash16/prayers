/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12468
  Name: Zapping
  Problem: https://onlinejudge.org/external/124/12468.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int a, b;
    while(cin>>a>>b && (a!=-1 || b!=-1)) {
        int diff = a>b ? a-b : b-a;
        cout << min(diff, 100-diff) << endl;
    }
}
