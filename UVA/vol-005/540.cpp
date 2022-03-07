/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 540
  Name: Team Queue
  Problem: https://onlinejudge.org/external/5/540.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

inline int readchar() {
    const int N = 1048576;
    static char buf[N];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}

inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readInt() {
    char ch;
    int sgn=1, r=0;
    while (!isdigit(ch=readchar()) && ch!='-');
    if (ch == '-') sgn = -1;
    else r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    return sgn*r;
}

inline char readCh() {
    char ch, ch2;
    while ((ch=readchar())==' ' || ch=='\n');
    while ((ch2=readchar())!=' ' && ch2!='\n');
    return ch;
}

// ---------------------------------------------------------------

class FastQueue {
    int data[1024], l, r;
    public:
        FastQueue():l(0),r(0) {}
        void clear() { l=r=0; }
        bool empty() { return l==r; }
        void push(int x) { data[r++] = x; r&=1023; }
        int pop(){ int result = data[l++]; l&=1023; return result; }
        int front() { return data[l]; }
};


int eteam[1000000];
FastQueue tqu[1000], mqu;

int main() {
    ios_base::sync_with_stdio(0);

    char cm;
    for (int cse=1, n; (n=readInt()); ++cse) {
        cout << "Scenario #" << cse << endl;

        for (int i=0; i<n; ++i) {
            int m = readInt();
            tqu[i].clear();
            for (int j=0; j<m; ++j)
                eteam[readInt()] = i;
        }

        mqu.clear();
        while ((cm=readCh())!='S') {
            if (cm == 'E') {
                int x = readInt(),
                    tid = eteam[x];
                if (tqu[tid].empty())
                    mqu.push(tid);
                tqu[tid].push(x);
            }
            else {
                int tid = mqu.front();
                cout << tqu[tid].front() << endl;
                tqu[tid].pop();
                if (tqu[tid].empty())
                    mqu.pop();
            }
        }
        cout << endl;
    }
}
