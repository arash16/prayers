/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 563
  Name: Crimewave
  Problem: https://onlinejudge.org/external/5/563.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

unsigned int seen[6000], scnt;
bool cap[6000][6000];
list<int> adj[6000];
void connect(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] = 1;
    cap[v][u] = 0;
}

int pre[100000];
int maxflow(int src, int dest) {
    int augments = 0;
    bool hasaug = 1;
    while (hasaug) {
        hasaug = 0;

        queue<int> q;
        q.push(src);
        seen[src] = ++scnt;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == dest) {
                for (; u!=src; u=pre[u]) {
                    cap[pre[u]][u] = 0;
                    cap[u][pre[u]] = 1;
                }

                augments++;
                hasaug = 1;
                break;
            }

            for (int v: adj[u])
                if (seen[v]!=scnt && cap[u][v]) {
                    seen[v] = scnt;
                    pre[v] = u;
                    q.push(v);
                }
        }
    }
    return augments;
}


bool rob[100][100];
int nx[]={0,0,1,-1},
    ny[]={1,-1,0,0};

int main(){
    int T, a, b, c, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        for (int i=0; i<=a+1; i++)
            for (int j=0; j<=b+1; j++)
                rob[i][j]=0;

        bool impo = 0;
        for (int i=0; i<c; i++) {
            scanf("%d%d", &u, &v);
            if (rob[--u][--v]) impo = 1;
            else rob[u][v] = 1;
        }
        if (impo) {
            puts("not possible");
            continue;
        }

        for (int k=a*b*2+2; k>=0; k--)
            adj[k].clear();

        int src=2*a*b+1, dest=2*a*b+2;
        for (int i=0; i<a; i++)
            for (int j=0; j<b; j++) {
                int id1 = 1 + 2*(i*b + j);
                if (rob[i][j]) connect(src, id1-1);
                connect(id1-1, id1);

                bool sink=0;
                for (int k=0; k<4; k++) {
                    int i2=i+ny[k], j2=j+nx[k];
                    if (i2>=0 && i2<a && j2>=0 && j2<b) {
                        if (!rob[i2][j2])
                            connect(id1, 2*(i2*b + j2));
                    }
                    else sink = 1;
                }
                if (sink) connect(id1, dest);
            }

        puts(maxflow(src, dest)==c ? "possible" : "not possible");
    }
}
