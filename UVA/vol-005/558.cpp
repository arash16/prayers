/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 558
  Name: Wormholes
  Problem: https://onlinejudge.org/external/5/558.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

#define INF 200000000

struct Edge {
    int x, y, w;
};
Edge eds[2001];
int d[1005];

bool hasCycle(int n, int m) {
    d[0]=0;
    for (int i=1; i<n; i++)
        d[i] = INF;

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            Edge &e = eds[j];
            if (d[e.x] + e.w < d[e.y])
                d[e.y] = d[e.x] + e.w;
        }

    for (int j=0; j<m; j++) {
        Edge &e = eds[j];
        if (d[e.x] <= 2000000)
        if (d[e.x] + e.w < d[e.y])
            return true;
    }
    return false;
}


int main(){
    int T, n, m;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        for (int i=0; i<m; i++) {
            Edge &e = eds[i];
            cin >> e.x >> e.y >> e.w;
        }

        cout << (hasCycle(n, m) ? "possible\n" : "not possible\n");
    }
}
