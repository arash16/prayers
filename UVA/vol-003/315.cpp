/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 315
  Name: Network
  Problem: https://onlinejudge.org/external/3/315.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[101];
int n, mp[101][101], par[101],
    seen[101], low[101], depth[101],
    arts;

void dfs(int v, int d) {
    seen[v] = true;
    depth[v] = low[v] = d;
    bool isArt = false;
    int childs = 0;

    for (int i=adj[v].size()-1; i>=0; i--) {
        int w = adj[v][i];
        if (!seen[w]) {
            childs++;
            par[w] = v;
            dfs(w, d+1);
            if (low[w] >= depth[v])
                isArt = true;
            if (low[w] < low[v])
                low[v] = low[w];
        }
        else if (w != par[v] && depth[w]<low[v])
            low[v] = depth[w];
    }

    if ((v && isArt) || (!v && childs>1)) arts++;
}


int main(){
    char line[1000];
    while (cin>>n && n) {
        for (int i=0; i<n; i++) {
            seen[i]=0;
            adj[i].clear();
            for (int j=i; j<n; j++)
                mp[i][j]=mp[j][i]=0;
        }

        cin.getline(line, 1000);
        while (cin.getline(line, 1000) && line[0]!='0') {
            int s = -1, x;
            for (char *p=strtok(line, " "); p; p=strtok(0, " ")) {
                sscanf(p,"%d", &x); x--;
                if (s<0) s=x;
                else if(!mp[s][x]) {
                    mp[s][x]=mp[x][s]=1;
                    adj[s].push_back(x);
                    adj[x].push_back(s);
                }
            }
        }

        arts = 0;
        dfs(0, 0);
        cout << arts << endl;
    }
}
