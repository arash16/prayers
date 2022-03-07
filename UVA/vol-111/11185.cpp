/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11185
  Name: Ternary
  Problem: https://onlinejudge.org/external/111/11185.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

void print3(long long int n) {
    if (!n) return;
    print3(n / 3);
    cout << (n%3);
}

int main(){
    long long int n;
    while (cin>>n && n>=0) {
        if (!n) cout<<0;
        else print3(n);
        cout<<endl;
    }
}
