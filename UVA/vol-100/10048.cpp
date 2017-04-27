#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


#define MAXN 1001

int ids[MAXN];
int find(int i) {
    if (ids[i] == i) return i;
    return ids[i] = find(ids[i]);
}
void join(int x, int y) {
    ids[find(x)] = find(y);
}


struct Edge {
    int x, y, d;
    bool operator < (const Edge &e) const {
        return d<e.d;
    }
};

Edge eds[MAXN];
vector<int> adj[MAXN];
int mp[MAXN][MAXN];
int seen[MAXN];

int dfs(int v, int w) {
    if (v==w) return 0;
    if (seen[v]) return -1;
    seen[v] = 1;

    int mx = -1;
    for (int i: adj[v]) {
        int r = dfs(i, w);
        if (r>=0)
            mx = max(mx, max(r, mp[v][i]));
    }

    seen[v] = 0;
    return mx;
}




int main(){
    int c,s,q, cse=1, x, y;
    while (cin>>c>>s>>q && (c||s||q)) {
        if (cse > 1) cout<<endl;
        printf("Case #%d\n", cse++);

        for (int i=0; i<=c; i++) {
            adj[i].clear();
            ids[i]=i;
        }

        for (int i=0; i<s; i++) {
            Edge &e = eds[i];
            cin >> e.x >> e.y >> e.d;
        }

        sort(eds, eds+s);
        int cnt = 0;
        for (int i=0; i<s && cnt<c-1; i++) {
            Edge &e = eds[i];
            if (find(e.x) != find(e.y)) {
                join(e.x, e.y);
                adj[e.x].push_back(e.y);
                adj[e.y].push_back(e.x);
                mp[e.x][e.y] = mp[e.y][e.x] = e.d;
            }
        }

        for (int i=0; i<q; i++) {
            cin>>x>>y;
            int r = dfs(x, y);
            if (r<0) cout<<"no path\n";
            else cout << r << endl;
        }
    }
}
