/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11608
  Name: No Problem
  Problem: https://onlinejudge.org/external/116/11608.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int cse=1, x, s, m[12];
    while (cin>>s && s>=0) {
        for (int i=0; i<12; i++)
            cin >> m[i];

        printf("Case %d:\n", cse++);
        for (int i=0; i<12; i++) {
            cin >> x;
            if (s >= x) {
                puts("No problem! :D");
                s -= x;
            }
            else puts("No problem. :(");
            s += m[i];
        }
    }
}
