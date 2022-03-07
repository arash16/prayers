/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 824
  Name: Coast Tracker
  Problem: https://onlinejudge.org/external/8/824.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int xx[] = {0, -1, -1, -1, 0, 1, 1, 1},
    yy[] = {1, 1, 0, -1, -1, -1, 0, 1},
    M[3][3];

int nextDir(int d) {
    for (int i=0; i<8; i++) {
        int nd = (d+6+i)%8;
        if (M[xx[nd]+1][yy[nd]+1])
            return nd;
    }
    return d;
}

int main() {
    int x, y, d, xi, yi, si;
    while (cin>>x>>y>>d && (x>=0 && y>=0 && d>=0)) {
        for (int i=0; i<8; i++) {
            cin>>xi>>yi>>si;
            M[xi-x+1][yi-y+1] = si;
        }
        cout << nextDir(d) << endl;
    }
}
