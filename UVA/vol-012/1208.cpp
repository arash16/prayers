#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

char gid[30];
char find(char u) {
    return gid[u]==u?u: gid[u] = find(gid[u]);
}
void join(char u, char v) {
    gid[find(u)]=find(v);
}

struct Edge {
    int w;
    char u, v;
    Edge(char u, char v, char w):u(u),v(v),w(w){}
    bool operator < (const Edge &e) const {
        return w > e.w;
    }
};


int main(){
    int T, n, w;
    scanf("%d", &T);
    for (int cse=1; cse<=T; ++cse) {
        scanf("%d", &n);
        priority_queue<Edge> q;
        for (int i=0; i<n; i++) {
            gid[i] = i;
            for (int j=0; j<n; j++) {
                scanf("%d%*[ \n\t,]", &w);
                if (i<j && w) q.push(Edge(i, j, w));
            }
        }

        printf("Case %d:\n", cse);
        for (int i=1; i<n;) {
            Edge e = q.top(); q.pop();
            if (find(e.u) != find(e.v)) {
                printf("%c-%c %d\n", e.u+'A', e.v+'A', e.w);
                join(e.u, e.v);
                ++i;
            }
        }
    }
}
