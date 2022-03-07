/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10505
  Name: Montesco vs Capuleto
  Problem: https://onlinejudge.org/external/105/10505.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

#define INF 1073741824
list<int> adj[202];
int color[202], cnt;

int dfs(int u) {
    int c = 1-color[u],
        sum = c;
    for (int v: adj[u])
        if (color[v]==-1) {
            cnt++;
            color[v] = c;
            sum += dfs(v);
        }
        else if (color[v] != c)
            sum = -INF;
    return sum;
}


int main(){
    int T, n, p, u;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=0; i<n; i++) {
            adj[i].clear();
            color[i]=-1;
        }

        for (int i=0; i<n; i++) {
            cin>>p;
            for (int j=0; j<p; j++) {
                cin >> u;
                adj[i].push_back(u-1);
                adj[u-1].push_back(i);
            }
        }

        int result = 0;
        for (int i=0; i<n; i++)
            if (color[i]==-1) {
                cnt = 1;
                color[i] = 0;
                int r = dfs(i);
                if (r > 0)
                result += max(r, cnt-r);
            }
        cout << result << endl;
    }
}
