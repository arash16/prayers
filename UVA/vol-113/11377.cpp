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

// --------------------------------------------------------------

template<class T>
class IndexQueue {
    int mind, maxd;
    vector<T> V[300000];
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

// ---------------------------------------------------------------------

vector<int> adj[2043];
int D[2043], A[2043], S[2043], SC=1;
IndexQueue<int> q;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    for (int cse=1; cse<=T; ++cse) {
        cout << "Case " << cse << ":\n";
        int n = readUInt(),
            m = readUInt(),
            k = readUInt();

        for (int i=0; i<n; ++i) {
            adj[i].clear();
            A[i] = 1;
        }

        for (int i=0; i<k; ++i)
            A[readUInt()-1] = 0;

        for (int i=0; i<m; ++i) {
            int u = readUInt()-1,
                v = readUInt()-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        m = readUInt();
        for (;m--; ++SC) {
            int src = readUInt()-1,
                dst = readUInt()-1;

            if (src == dst) cout << "0\n";
            else {
                q.clear();
                q.push(D[src]=A[src], src);
                S[src] = SC;
                while (!q.empty()) {
                    int d = q.top(),
                        u = q.pop();
                    if (S[u]==SC && d != D[u]) continue;
                    if (u == dst ) {
                        cout << d << endl;
                        goto fin;
                    }

                    for (int v: adj[u]) {
                        int dd = d + A[v];
                        if (S[v]!=SC || dd < D[v]) {
                            S[v] =SC;
                            q.push(D[v]=dd, v);
                        }
                    }
                }
                cout << "-1\n";
            }
            fin:;
        }
        cout << endl;
    }
}
