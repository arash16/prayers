/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11494
  Name: Queen
  Problem: https://onlinejudge.org/external/114/11494.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int x1,y1, x2,y2;
    while (cin>>x1>>y1>>x2>>y2 && (x1||y1||x2||y2)) {
        if (x1==x2 && y1==y2) puts("0");
        else if (x1==x2 || y1==y2 || x1-x2==y1-y2 || x2-x1==y1-y2)
             puts("1");
        else puts("2");
    }
}
