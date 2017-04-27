#include <stdio.h>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
            fin = 1;
            return EOF;
        }
        p = buf;
    }
    return *p++;
}

bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline unsigned int readUInt() {
    char ch;
    unsigned int r=0;
    while (!isdigit(ch=readchar()));
    r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    return r;
}

bool readStr(char *str) {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    if (ch == EOF) return 0;

    *str++ = ch;
    while ((ch=readchar())!=' ' && ch!='\n' && ch!=EOF)
        *str++ = ch;
    *str = 0;
    return 1;
}

// ------------------------------------------------------------


#define MAXN 417
int par[MAXN];
int find(int u) { return par[u]<0 ? u : par[u]=find(par[u]); }
void join(int u, int v) {
    if ((u=find(u)) == (v=find(v))) return;
    if (par[v] < par[u])
        swap(u, v);
    par[u] += par[v];
    par[v] = u;
}


struct Edge {
    int u, v, w;
    bool operator < (const Edge &e) const { return w < e.w; }
} q[79801];

int main(){
    int n, m, w, c;
    char s1[100], s2[100];
    while ((n=readUInt())) {
        int m = readUInt();
        unordered_map<string, short> ids;
        for (int i=0; i<n; i++) {
            readStr(s1);
            ids[s1] = i;
        }

        memset(par, -1, n*sizeof(int));
        for (int i=0; i<m; i++) {
            readStr(s1); q[i].u = ids[s1];
            readStr(s2); q[i].v = ids[s2];
            q[i].w = readUInt();
        }
        readStr(s1);
        sort(q, q+m);

        int sum = 0, c=1;
        for (int i=0; c<n && i<m; ++i) {
            int u = q[i].u, v = q[i].v;
            if (find(u) != find(v)) {
                sum += q[i].w;
                join(u, v);
                ++c;
            }
        }
        if (c < n) puts("Impossible");
        else printf("%d\n", sum);
    }
}
