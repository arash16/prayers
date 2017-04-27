#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

#define INF 1073741824

struct VD {
    int id, d;
    VD (int id, int d): id(id), d(d) {}
    bool operator < (const VD& o) const {
        return d > o.d;
    }
};


list<int> adj[26];
int dist[26][26];
bool seen[26];

int main(){
    int u, v;
    char word[100];
    while (cin >> word) {
        for (int i=0; i<26; i++)
            adj[i].clear();

        int sum = 0;
        while (strcmp(word, "deadend")) {
            int len = strlen(word);
            sum += len;

            u = word[0]-'a';
            v = word[len-1]-'a';
            adj[u].push_back(v);
            adj[v].push_back(u);
            dist[u][v] = dist[v][u] = len;

            cin >> word;
        }

        int s=-1, t=-1;
        for (int i=0; i<26 && t==-1; i++)
            if (adj[i].size()%2)
                if (s==-1) s = i;
                else t = i;

        if (t != -1) {
            memset(seen, 0, sizeof(seen));
            priority_queue<VD> q;
            q.push(VD(s, 0));

            while (!q.empty()) {
                VD u = q.top(); q.pop();
                if (u.id == t) { sum += u.d; break; }
                if (seen[u.id]) continue;
                seen[u.id] = true;
                for (int v: adj[u.id])
                    if (!seen[v])
                        q.push(VD(v, u.d + dist[u.id][v]));
            }
        }

        cout << sum << endl;
    }
}
