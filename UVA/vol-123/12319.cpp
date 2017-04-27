#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

inline int readchar(bool peek=0) {
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
    int r = *p;
    if (!peek) ++p;
    return r;
}

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
    char ch;
    unsigned int r=0;
    while (!isdigit(ch=readchar()))
        if (ch == EOF) return EOF;
    r = ch-'0';
    while (isdigit(ch=readchar(1))) {
        r = (r<<3) + (r<<1) + ch-'0';
        readchar();
    }

    while (readchar(1) == ' ')
        readchar();

    return r;
}

// -------------------------------------------------------------------


#define MAXQS 128
class FastQueue {
    int data[MAXQS], l, r;
    public:
        FastQueue():l(0),r(0) {}
        void clear() { l=r=0; }
        bool empty() { return l==r; }
        void push(int x) { data[r++] = x; r&=MAXQS-1; }
        int pop(){ int result = data[l++]; l&=MAXQS-1; return result; }
        int front() { return data[l]; }
        int size() { return r>=l ? r-l : MAXQS-l+r; }
} q;

void bfs(int n, int src, const vector<int> adj[], int D[]) {
    for (int i=0; i<n; ++i)
        D[i] = INF;

    q.clear();
    D[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.pop();
        for (int v: adj[u])
            if (D[v] == INF) {
                D[v] = D[u] + 1;
                q.push(v);
            }
    }
}

vector<int> adj[2][143];
int D[2][143][143];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1, n; (n=readUInt()); ++cse) {
        for (int i=0; i<n; ++i) {
            adj[0][i].clear();
            adj[1][i].clear();
        }

        for (int d=0; d<2; ++d) {
            for (int i=0; i<n; ++i) {
                int u = readUInt() - 1;
                while (readchar(1) != '\n') {
                    int v = readUInt() - 1;
                    adj[d][u].push_back(v);
                }
            }

            for (int i=0; i<n; ++i)
                bfs(n, i, adj[d], D[d][i]);
        }

        int a = readUInt(),
            b = readUInt();

        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (D[1][i][j] > a*D[0][i][j]+b) {
                    cout << "No\n";
                    goto fin;
                }
        cout << "Yes\n";
        fin:;
    }
}
