#include <stdio.h>
#include <iostream>
#include <cstring>
#include <list>
using namespace std;

list<int> adj[110];
bool h[110];
int d[110];

int main(){
    for (int cse=1; ;cse++) {
        int u, v, n=0;
        memset(h, 0, sizeof(h));
        while (cin>>u>>v && (u || v)) {
            n = max(n, max(u, v));
            if (!h[u-1]) {
                adj[u-1].clear();
                h[u-1]=1;
            }
            if (!h[v-1]) {
                adj[v-1].clear();
                h[v-1]=1;
            }
            adj[u-1].push_back(v-1);
        }
        if (!n) break;

        int sum=0, cnt=0;
        for (int i=0; i<n; i++)
            if (h[i]) {
                cnt++;
                memset(d, -1, sizeof(int)*n);
                list<int> q;
                q.push_back(i);
                d[i] = 0;
                while (!q.empty()) {
                    int u = q.front(); q.pop_front();
                    for (int v: adj[u])
                        if (d[v] < 0) {
                            d[v] = d[u] + 1;
                            sum += d[v];
                            q.push_back(v);
                        }
                }
            }
        printf("Case %d: average length between pages = %.3f clicks\n", cse, sum/(cnt*(cnt-1.0)));
    }
}
