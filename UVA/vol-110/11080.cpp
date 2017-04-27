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
            if (sum < 0)
                return -INF;
        }
        else if (color[v]!=c)
            return -INF;
    return sum;
}


int main(){
    int T, n, m, u, v;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) {
            adj[i].clear();
            color[i]=-1;
        }

        for (int i=0; i<m; i++) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int result = 0;
        for (int i=0; i<n; i++)
            if (color[i] == -1) {
                cnt = 1;
                color[i] = 0;
                int r = dfs(i);
                if (r >= 0)
                    result += max(1, min(r, cnt-r));
                else {
                    result = -1;
                    break;
                }
            }
        cout << result << endl;
    }
}
