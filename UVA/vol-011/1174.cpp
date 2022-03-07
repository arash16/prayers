/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1174
  Name: IP-TV
  Problem: https://onlinejudge.org/external/11/1174.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

short gid[2017];
short find(short u) {
    return gid[u]==u ? u : gid[u]=find(gid[u]);
}
void join(short u, short v) {
    gid[find(u)] = find(v);
}

short idcnt;
unordered_map<string, short> ids;
short getId(const char s[]) {
    auto it = ids.find(s);
    if (it != ids.end())
        return it->second;
    return ids[s] = idcnt++;
}

struct Edge {
    int w;
    short u, v;
    Edge(short u, short v, int w):u(u),v(v),w(w){}
    bool operator < (const Edge &e) const {
        return w > e.w;
    }
};


int main(){
    int T, n, m, w;
    scanf("%d", &T);
    char s1[100], s2[100];
    while (T--) {
        scanf("%d%d", &n, &m);

        ids.clear(); idcnt = 0;
        for (int i=0; i<n; ++i)
            gid[i] = i;

        priority_queue<Edge> q;
        for (int i=0; i<m; i++) {
            scanf("%s%s%d", s1, s2, &w);
            q.push(Edge(getId(s1), getId(s2), w));
        }

        int sum = 0;
        for (int i=1; i<n;) {
            Edge e = q.top(); q.pop();
            if (find(e.u) != find(e.v)) {
                join(e.u, e.v);
                sum += e.w;
                ++i;
            }
        }
        printf("%d\n", sum);
        if (T) putchar('\n');
    }
}
