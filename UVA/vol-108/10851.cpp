/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10851
  Name: 2D Hieroglyphs decoder
  Problem: https://onlinejudge.org/external/108/10851.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

char lines[100][100];
int main(){
    int T;
    scanf("%d", &T);
    while (T--) {
        cin.getline(lines[0], 100);
        for (int i=0; i<10; i++)
            cin.getline(lines[i], 100);

        char msg[100];
        for (int i=1; lines[0][i+1]; i++) {
            int ch = msg[i] = 0;
            for (int j=8; j>0; j--)
                ch = (ch<<1) + (lines[j][i]=='\\' ? 1 : 0);
            msg[i-1] = ch;
        }
        puts(msg);
    }
}
