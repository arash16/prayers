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

inline int readStr(char *str) {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    if (ch == EOF) return 0;

    int l = 0;
    str[l++] = ch;
    while ((ch=readchar())!=' ' && ch!='\n' && ch!=EOF)
        str[l++] = ch;
    str[l] = 0;
    return l;
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

struct State {
    int u, s, d;
    State(int u, char s, int d):u(u),s(s),d(d){}
    bool operator < (const State &o) const { return d > o.d; }
};

int D[4013][27];
vector<State> adj[4013];

int icnt;
unordered_map<string, int> ids;
int readLid() {
    char s[60]; readStr(s);
    auto r = ids.emplace(s, icnt);
    if (r.second) {
        adj[icnt].clear();
        for (int i=0; i<27; ++i)
            D[icnt][i] = INF;
        ++icnt;
    }
    return r.first->second;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char s[60];
    for (int n; (n=readUInt()); ) {
        ids.clear(); icnt=0;
        int src = readLid(),
            dst = readLid();

        for (int i=0; i<n; ++i) {
            int u = readLid(),
                v = readLid(),
                d = readStr(s);

            adj[u].push_back(State(v, s[0]-96, d));
            adj[v].push_back(State(u, s[0]-96, d));
        }

        if (src != dst) {
            priority_queue<State> q;
            q.push(State(src, 0, D[src][0]=0));
            while (!q.empty()) {
                State s = q.top(); q.pop();
                if (s.d != D[s.u][s.s]) continue;
                if (s.u == dst) {
                    cout << s.d << endl;
                    goto fin;
                }

                for (State &t: adj[s.u]) if (s.s!=t.s) {
                    int d = s.d + t.d;
                    if (d < D[t.u][t.s])
                        q.push(State(t.u, t.s, D[t.u][t.s]=d));
                }
            }
        }
        cout << "impossivel\n";
        fin:;
    }
}
