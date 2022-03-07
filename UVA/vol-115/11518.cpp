/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11518
  Name: Dominos 2
  Problem: https://onlinejudge.org/external/115/11518.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <vector>
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

// -------------------------------------------------------------------

#define MAXN 10017
vector<int> adj[MAXN];
bool seen[MAXN];
void dfs(int u) {
    seen[u] = 1;
    for (int v: adj[u])
        if (!seen[v])
            dfs(v);
}


int main() {
    int T = readUInt();
    while (T--) {
        int n = readUInt(),
            m = readUInt(),
            l = readUInt();

        for (int i=0; i<n; ++i)
            adj[i].clear(),
            seen[i] = 0;

        for (int i=0; i<m; ++i) {
            int u = readUInt()-1,
                v = readUInt()-1;
            adj[u].push_back(v);
        }

        for (int i=0; i<l; ++i)
            dfs(readUInt()-1);

        int sum = 0;
        for (int i=0; i<n; ++i)
            sum += seen[i];

        printf("%d\n", sum);
    }
}
