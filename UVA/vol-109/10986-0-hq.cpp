/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10986
  Name: Sending email
  Problem: https://onlinejudge.org/external/109/10986.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
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

// -------------------------------------------------------------------

template<class T, int MAXI=100000>
class HybridQueue {
    public:
    struct Node {
        int key;
        T data;
        Node(int key, T data):key(key),data(data){}
        bool operator < (const Node& n) const { return key > n.key; }
    };

    private:
    int mind, maxd;
    vector<T> V[MAXI];
    priority_queue<Node> pq;

    void _reset() {
        mind=MAXI; maxd=-1;
    }

    public:
    HybridQueue() { _reset(); }
    bool empty() { return mind>maxd && pq.empty(); }
    void clear() {
        pq = priority_queue<Node>();
        for (int i=mind; i<=maxd; ++i)
            V[i].clear();
        _reset();
    }

    void push(int key, T data) {
        if (key < MAXI) {
            V[key].push_back(data);
            if (key < mind) mind = key;
            if (key > maxd) maxd = key;
        }
        else pq.push(Node(key, data));
    }

    Node top() {
        return mind <= maxd
            ? Node(mind, V[mind].back())
            : pq.top();
    }

    Node pop() {
        if (mind > maxd) {
            Node r = pq.top();
            pq.pop();
            return r;
        }

        Node r(mind, V[mind].back());

        V[mind].pop_back();
        while (mind<=maxd && V[mind].empty()) ++mind;
        if (mind>maxd) _reset();

        return r;
    }
};

// -------------------------------------------------------------------

#define INF 2147483647

struct UD {
    int u, d;
    UD(int u, int d):u(u),d(d){}
    bool operator < (const UD& ud) const { return d > ud.d; }
};

vector<UD> adj[20017];
int D[20017];


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    HybridQueue<int> q;

    int T = readUInt();
    for (int cse=1; cse<=T; ++cse) {
        cout << "Case #" << cse << ": ";

        int n = readUInt(),
            m = readUInt(),
            src = readUInt(),
            dst = readUInt();

        for (int i=0; i<n; ++i) {
            adj[i].clear();
            D[i] = INF;
        }

        for (int i=0; i<m; ++i) {
            int u = readUInt(),
                v = readUInt(),
                w = readUInt();

            adj[u].push_back(UD(v, w));
            adj[v].push_back(UD(u, w));
        }

        q.clear();
        q.push(D[src]=0, src);
        while (!q.empty()) {
            auto ud = q.top(); q.pop();
            int d = ud.key,
                u = ud.data;
            if (D[u] != d) continue;
            if (u == dst) {
                cout << d << endl;
                goto fin;
            }

            for (UD vd: adj[u]) {
                if (d+vd.d < D[vd.u]) {
                    D[vd.u] = d+vd.d;
                    q.push(d+vd.d, vd.u);
                }
            }
        }
        cout << "unreachable\n";
        fin:;
    }
}
