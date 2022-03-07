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

template<class T>
class BucketQueue {
    public:
    struct Node {
        int key;
        T data;
        Node(int key, T data):key(key),data(data){}
        bool operator < (const Node& n) const { return key > n.key; }
    };

    private:
    static const int BucketSize = 131072;
    static const int BucketCount = 16384;

    int curb, mind, maxd, minb, maxb;
    vector<Node> B[BucketCount];
    vector<T> V[BucketSize];
    priority_queue<Node> pq;

    void _reset() {
        maxb = minb = curb = 0;
        mind = BucketSize;
        maxd = -1;
    }

    void _update() {
        while (mind <= maxd && V[mind].empty())
            ++mind;

        if (mind > maxd) {
            while (B[minb].empty()) ++minb;
            if (minb>curb && minb <= maxb) {
                mind = BucketSize; maxd = -1;

                curb = minb;
                for (Node n: B[curb])
                    push(n.key, n.data);
                B[curb].clear();
            }
            else _reset();
        }
    }


    public:
    BucketQueue() { _reset(); }
    bool empty() {
        if (!pq.empty()) return 0;
        _update();
        return mind>maxd;
    }

    void clear() {
        if (!pq.empty())
            pq = priority_queue<Node>();

        for (int i=mind; i<=maxd; ++i)
            V[i].clear();

        for (int i=minb; i<=maxb; ++i)
            B[i].clear();

        _reset();
    }

    void push(int key, T data) {
        int b = key >> 17;
        if (b > curb) {
            B[b].push_back(Node(key, data));
            if (b < minb) minb = b;
            if (b > maxb) maxb = b;
        }

        else if (b < curb)
            pq.push(Node(key, data));

        else {
            key &= (BucketSize-1);
            V[key].push_back(data);
            if (key < mind) mind = key;
            if (key > maxd) maxd = key;
        }
    }

    Node top() {
        if (!pq.empty())
            return pq.top();

        _update();
        return Node(mind | (curb << 17), V[mind].back());
    }

    Node pop() {
        Node r = top();
        if (pq.empty())
            V[mind].pop_back();
        else
            pq.pop();
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


BucketQueue<int> q;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

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
