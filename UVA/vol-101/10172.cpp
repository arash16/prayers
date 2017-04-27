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

// ------------------------------------------------------------------

class FastQueue {
    int data[128], l, r;
    public:
        FastQueue():l(0),r(0) {}
        void clear() { l=r=0; }
        bool empty() { return l==r; }
        void push(int x) { data[r++] = x; r&=127; }
        int pop(){ int result = data[l++]; l&=127; return result; }
        int front() { return data[l]; }
        int size() { return r>=l ? r-l : 128-l+r; }
};

class FastStack {
    int data[128], sz;
    public:
        FastStack():sz(0){}
        void clear() { sz=0; }
        bool empty() { return !sz; }
        void push(int x) { data[sz++] = x; }
        int pop() { return data[--sz]; }
        int top() { return data[sz-1]; }
        int size() { return sz; }
};


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    FastQueue q[101];
    int T = readUInt();
    while (T--) {
        int n = readUInt(),
            maxs = readUInt(),
            maxq = readUInt();

        int total = 0;
        for (int i=0; i<n; ++i) {
            q[i].clear();
            for (int j=readUInt(); j; --j)
                q[i].push(readUInt()-1);
            total += q[i].size();
        }

        int tm = -2;
        FastStack s;
        for (int i=0; total; i=(i+1)%n) {
            tm += 2;
            while (s.size())
                if (s.top() == i) {
                    s.pop();
                    --total;
                    ++tm;
                }
                else if (q[i].size() < maxq) {
                    q[i].push(s.pop());
                    ++tm;
                }
                else break;

            while (q[i].size() && s.size()<maxs) {
                s.push(q[i].pop());
                ++tm;
            }
        }
        cout << tm << endl;
    }
}
