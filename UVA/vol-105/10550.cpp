/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10550
  Name: Combination Lock
  Problem: https://onlinejudge.org/external/105/10550.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int sub(int a, int b) {
    return (a<b ? b-a : 40-a+b)%40;
}

int main(){
    int i, a, b, c;
    while(cin>>i>>a>>b>>c && (i||a||b||c)){
        int cm = 3*40 + sub(a, i) + sub(a, b) + sub(c, b);
        cout << cm*9 <<endl;
    }
}

