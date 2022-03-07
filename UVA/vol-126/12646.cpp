/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12646
  Name: Zero or One
  Problem: https://onlinejudge.org/external/126/12646.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    while (cin>>a>>b>>c) {
        int t = (a<<2)+(b<<1)+c;
        if (t==7 || t==0) puts("*");
        else if (t==6 || t==1) puts("C");
        else if (t==5 || t==2) puts("B");
        else puts("A");
    }
}
