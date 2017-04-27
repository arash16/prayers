#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <map>
using namespace std;

#define MAXN 30
int cnt;
map<string, int> ids;
string names[MAXN];

int readId() {
    string s; cin>>s;

    auto it = ids.find(s);
    if (it == ids.end()) {
        names[cnt] = s;
        return ids[s] = cnt++;
    }
    return it->second;
}


list<int> adj[MAXN];
int low[MAXN], pre[MAXN], pcnt;
bool onstack[MAXN];
stack<int> S;

void cc(int u) {
    low[u] = pre[u] = pcnt++;
    onstack[u] = 1;
    S.push(u);

    for (int v: adj[u])
        if (pre[v] < 0) {
            cc(v);
            low[u] = min(low[u], low[v]);
        }
        else if (onstack[v])
            low[u] = min(low[u], pre[v]);

    if (low[u] == pre[u]) {
        int v;
        for (; (v=S.top()) != u; S.pop()) {
            cout << names[v] << ", ";
            onstack[v] = 0;
        }
        cout << names[v] << endl;
        onstack[v] = 0;
        S.pop();
    }
}

int main(){
    int cse=1, n, m;
    while (cin>>n>>m && (n||m)) {
        for (int i=0; i<n; i++) {
            adj[i].clear();
            onstack[i] = 0;
            pre[i] = -1;
        }
        ids.clear();
        cnt=pcnt=0;

        for (int i=0; i<m; i++) {
            int u=readId(),
                v=readId();
            adj[u].push_back(v);
        }

        if (cse > 1) putchar('\n');
        printf("Calling circles for data set %d:\n",cse++);
        for (int i=0; i<n; i++)
            if (pre[i] < 0)
                cc(i);
    }
}
