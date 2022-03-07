/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 439
  Name: Knight Moves
  Problem: https://onlinejudge.org/external/4/439.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int abs(int n) {
    return n<0 ? -n : n;
}

int d[64][64];
int main(){
    for (int i=0; i<64; i++) {
        int x1=i%8, y1=i/8;
        for (int j=0; j<64; j++)
            if (i!=j) {
                int x2=j%8, y2=j/8;

                if ((abs(x1-x2)==2 && abs(y1-y2)==1) || (abs(x1-x2)==1 && abs(y1-y2)==2))
                    d[i][j] = 1;
                else
                    d[i][j]=1000;
            }
    }

    for (int k=0; k<64; k++)
        for (int i=0; i<64; i++)
            for (int j=0; j<64; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];

    char c1,c2;
    int d1,d2;
    while(scanf(" %c%d %c%d",&c1,&d1,&c2,&d2)==4) {
        int moves = d[(c1-'a')*8 + d1 - 1][(c2-'a')*8 + d2 - 1];
        printf("To get from %c%d to %c%d takes %d knight moves.\n", c1,d1, c2,d2, moves);
    }
}
