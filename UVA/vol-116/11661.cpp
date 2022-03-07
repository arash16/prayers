/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11661
  Name: Burger Time?
  Problem: https://onlinejudge.org/external/116/11661.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 3000000

int main(){
    int l;
    while (cin>>l && l) {
        while (getchar()!='\n');

        int mn=INF;
        int lastD=-INF, lastR=-INF;
        for (int i=0; i<l; i++) {
            char ch = getchar();
            if (ch == 'Z') mn=0;
            else if (ch == 'R') {
                mn = min(mn, i-lastD);
                lastR = i;
            }
            else if (ch == 'D') {
                mn = min(mn, i-lastR);
                lastD = i;
            }
        }

        cout << mn << endl;
    }
}
