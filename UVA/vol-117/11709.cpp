#include <stdio.h>
#include <iostream>
#include <stack>
#include <list>
#include <map>
using namespace std;

#define MAXN 1001
map<string, int> ids;
list<int> adj[MAXN];


int pre[MAXN], low[MAXN], pcnt, result;
bool onstack[MAXN];
stack<int> S;

void scc(int u) {
    low[u]=pre[u]=pcnt++;
    onstack[u] = 1;
    S.push(u);

    for (int v: adj[u])
        if (pre[v] < 0) {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
        else if (onstack[v])
            low[u] = min(low[u], pre[v]);

    if (low[u] == pre[u]) {
        result++;
        onstack[u] = 0;
        while (S.top() != u) {
            onstack[S.top()] = 0;
            S.pop();
        }
        S.pop();
    }
}



int main(){
    int n, m;
    char w1[50], w2[50];
    while (cin>>n>>m && (n||m)) {
        while (getchar()!='\n');
        for (int i=0; i<n; i++) {
            adj[i].clear();
            cin.getline(w1, 50);
            ids[w1] = i;
            pre[i] = -1;
        }

        for (int i=0; i<m; i++) {
            cin.getline(w1, 50);
            cin.getline(w2, 50);
            adj[ids[w1]].push_back(ids[w2]);
        }

        result=pcnt=0;
        for (int i=0; i<n; i++)
            if (pre[i] < 0)
                scc(i);

        cout << result << endl;
    }
}
