/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11716
  Name: Digital Fortress
  Problem: https://onlinejudge.org/external/117/11716.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXL 10010
char line[10010];

int main(){
    int T, len;
    cin>>T; cin.getline(line, MAXL);
    while (T--) {
        cin.getline(line, MAXL);
        len = cin.gcount() - 1;
        int sq = sqrt((double)len);
        if (sq * sq != len) puts("INVALID");
        else {
            for (int i=0; i<sq; i++)
                for (int j=0; j<sq; j++)
                    putchar(line[sq*j + i]);
            putchar('\n');
        }
    }
}
