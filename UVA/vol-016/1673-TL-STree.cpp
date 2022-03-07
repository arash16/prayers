/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1673
  Name: str2int
  Problem: https://onlinejudge.org/external/16/1673.pdf
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

//---------------------------------------------------------------



class SuffixTree {
    static const int MAXL = 100043;
    static const int SIGM = 11;

    string S;
    int getId(int i) { return S[i] - '0'; }
    // separator -> ':'

    // -------------------------------------------------------------------

    int Nc;
    struct Node {
        int suffix, E[SIGM];
    } Nodes[MAXL*2];
    int newNode() {
        Node &nd = Nodes[Nc];
        memset(nd.E, -1, SIGM*sizeof(int));
        nd.suffix = -1;
        return Nc++;
    }

    // -------------------------------------------------------------------

    int Ec;
    struct Edge {
        int to, i, j;
    } Edges[MAXL*2*SIGM];
    int newEdge(int frm, int i, int j) {
        Edge &e = Edges[Ec];
        e.to = newNode();
        e.i = i; e.j = j;
        Nodes[frm].E[ getId(i) ] = Ec;
        return Ec++;
    }

    // -------------------------------------------------------------------

    struct Suffix {
        int node, i, j;
        Suffix(int node, int i, int j):node(node),i(i),j(j){}
        bool isExplicit() { return i > j; }
    };
    void canonize(Suffix &s) {
        while (!s.isExplicit()) {
            Edge &e = Edges[Nodes[s.node].E[ getId(s.i) ]];
            int span = e.j - e.i;
            if (span > s.j - s.i) break;
            s.i += span + 1;
            s.node = e.to;
        }
    }

    // -------------------------------------------------------------------

    int SplitEdge(Suffix &s) {
        int span = s.j-s.i,
            id = getId(s.i),
            ei = Nodes[s.node].E[id];
        Nodes[s.node].E[id] = -1;
        Edge &oe = Edges[ei];

        int nn = Edges[newEdge(s.node, oe.i, oe.i + span)].to;
        Nodes[nn].E[ getId(oe.i += span+1) ] = ei;
        Nodes[nn].suffix = s.node;
        return nn;
    }

    void AddPrefix(Suffix &active, int lasti) {
        int last_parent=-1,
            parent_node;

        for (;;) {
            parent_node = active.node;

            if (active.isExplicit()) {
                if (Nodes[active.node].E[ getId(lasti) ] >= 0)
                    break;
            } else {
                Edge &e = Edges[Nodes[active.node].E[ getId(active.i) ]];
                int span = active.j - active.i;
                if (S[e.i+span+1] == S[lasti]) break;
                parent_node = SplitEdge(active);
            }

            newEdge(parent_node, lasti, S.length()-1);
            if (last_parent != -1)
                Nodes[ last_parent ].suffix = parent_node;
            last_parent = parent_node;

            if (!active.node)
                 active.i++;
            else active.node = Nodes[ active.node ].suffix;
            canonize(active);
        }
        if (last_parent != -1)
            Nodes[ last_parent ].suffix = parent_node;
        active.j++;
        canonize(active);
    };



    public:
    void clear() {
        Ec = Nc = 0;
        newNode();
    }

    SuffixTree() { clear(); }


    void build(char *s) {
        S = s;
        if (S[S.length()-1] != ':')
            S += ':';
        Suffix active(0, 0, -1);
        for (int i=0; i<S.length(); i++)
            AddPrefix(active, i);
    }

    void printAll(string str="", int node=0) {
        cout << str << endl;
        Node &n = Nodes[node];
        for (int i=0; i<=10; ++i)
            if (n.E[i]!=-1) {
                Edge &e = Edges[n.E[i]];
                printAll(str + "-" + S.substr(e.i, e.j-e.i+1), e.to);
            }
    }

    int sumUnique(int x=0, int node=0) {
        int sum = 0;
        Node &n = Nodes[node];
        for (int k, i=node==0; i<10; ++i)
            if (n.E[i]!=-1) {
                int tsum = x;
                Edge &e = Edges[n.E[i]];
                for (k=e.i; k<=e.j && S[k]!=':'; ++k) {
                    tsum = (tsum*10 + getId(k)) % 2012;
                    sum = (sum + tsum) % 2012;
                }

                if (k > e.j)
                    sum = (sum + sumUnique(tsum, e.to)) % 2012;
            }

        return sum;
    }
};


SuffixTree st;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    char s[200043];
    while ((n=readUInt())!=EOF) {
        int l = 0;
        for (int i=0; i<n; ++i) {
            int ll = readStr(s + l);
            s[l + ll++] = ':';
            l += ll;
        }
        s[l] = 0;

        st.clear();
        st.build(s);
        cout << st.sumUnique() << endl;
    }
}
