/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10099
  Name: The Tourist Guide
  Problem: https://onlinejudge.org/external/100/10099.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 2147483647
#define MAXN 110


int dids[MAXN];
int find(int v) {
    if (dids[v] != v)
        return dids[v]=find(dids[v]);
    return v;
}

void join(int v, int w) {
    dids[find(v)] = find(w);
}



struct Edge {
    int x, y, w;
    bool operator < (const Edge& e) const {
        return w > e.w;
    }
};

Edge es[MAXN*MAXN];

int mp[MAXN][MAXN],
    adj[MAXN][MAXN],
    deg[MAXN], n, d;

int seen[MAXN], best;
bool findB(int v) {
    if (v==d)
        return true;

    if (!seen[v]) {
        seen[v] = true;
        for (int i=0; i<deg[v]; i++) {
            int y = adj[v][i];
            if (findB(y)) {
                if (mp[v][y] < best)
                    best=mp[v][y];
                return true;
            }
        }
    }
    return false;
}

int main(){
    int r, s, t, cse=1;
    while (cin>>n>>r && (n||r)) {
        for (int i=0; i<n; i++) {
            dids[i]=i;
            deg[i]=seen[i]=0;
            for (int j=i; j<n; j++)
                mp[i][j]=mp[j][i]=INF;
        }

        for (int i=0; i<r; i++) {
            Edge& e = es[i];
            cin >> e.x >> e.y >> e.w;
            e.x--; e.y--;
        }
        cin>>s>>d>>t;
        s--; d--;

        int cnt = 0;
        sort(es, es+r);
        for (int i=0; i<r && cnt<n-1; i++) {
            Edge& e = es[i];
            if (find(e.x) != find(e.y)) {
                cnt++;
                join(e.x, e.y);

                adj[e.x][deg[e.x]++] = e.y;
                adj[e.y][deg[e.y]++] = e.x;
                mp[e.x][e.y] = mp[e.y][e.x] = e.w;
            }
        }

        best = INF;
        findB(s);
        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", cse++, (int)ceil(t/(best-1.0)));
    }
}
