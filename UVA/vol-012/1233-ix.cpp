#include <bits/stdc++.h>
#define INF 1073741824
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

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
    char ch;
    unsigned int r=0;
    while (!isdigit(ch=readchar()))
        if (ch == EOF) return EOF;
    r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';

    while (ch!=' ' && ch!='\n')
        ch = readchar();
    return r;
}

// ----------------------------------------------------------------------

template<class T>
class IndexQueue {
    int mind, maxd;
    vector<T> V[1000000];
    void _update() {
        while (mind<=maxd && V[mind].empty()) ++mind;
        if (mind>maxd) clear();
    }

    public:
    IndexQueue() { mind=INF; maxd=-1; }
    bool empty() { _update(); return mind>maxd; }
    void clear() {
        for (int i=mind; i<=maxd; ++i)
            V[i].clear();
        mind=INF;
        maxd=-1;
    }

    void push(int key, T data) {
        V[key].push_back(data);
        if (key < mind) mind = key;
        if (key > maxd) maxd = key;
    }

    int top() { return mind; }
    T pop() {
        _update();
        T r = V[mind].back();
        V[mind].pop_back();
        return r;
    }
};

// ----------------------------------------------------------------------

vector<int> adj[555];
int D[555], W[555][555], S[555][555];
IndexQueue<int> q;

int main() {
    ios_base::sync_with_stdio(0);

    int T = readUInt();
    for (int cse=1; cse<=T; ++cse) {
        int c = readUInt(),
            n = readUInt() + 1,
            m = readUInt();

        q.clear();
        for (int i=0; i<n; ++i) D[i] = INF;
        for (int i=0; i<m; ++i) {
            int u = readUInt();
            q.push(D[u]=0, u);
        }

        for (int u=1; u<n; ++u) {
            m = readUInt();
            adj[u].clear();
            while (m--) {
                int d = readUInt(),
                    v = readUInt();
                if (S[u][v]!= cse) {
                    S[u][v] = cse;
                    W[u][v] = d;
                    adj[u].push_back(v);
                }
                else W[u][v] = min(W[u][v], d);
            }
        }


        while (!q.empty()) {
            int sd = q.top(),
                su = q.pop();
            if (sd != D[su]) continue;
            if (su == 0) {
                cout << (c-2) / (sd-1) << endl;
                goto fin;
            }

            for (int v: adj[su]) {
                int d = sd + W[su][v];
                if (d < D[v] && d < c)
                    q.push(D[v]=d, v);
            }
        }
        cout << "0\n";
        fin:;
    }
}
