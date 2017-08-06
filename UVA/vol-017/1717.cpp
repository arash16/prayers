#include <bits/stdc++.h>
using namespace std;

inline int readchar(bool skip=true) {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    static bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
            fin = 1;
            return EOF;
        }
        p = buf;
    }
    int result = *p;
    if (skip) ++p;
    return result;
}

inline char readNonBlankChar() {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    if (ch == EOF) return EOF;
    return ch;
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
inline int readInt() {
    char ch;
    int sgn=1, r=0;
    while (!isdigit(ch=readchar()) && ch!='-')
        if (ch == EOF) return EOF;
    if (ch == '-') sgn = -1;
    else r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    return sgn*r;
}

// ----------------------------------------------------------------

struct Event {
    double time;
    bool tp;
    Event(double t, bool tp):time(t),tp(tp){};
    bool operator < (const Event &o) const { return time < o.time; }
};

int main() {
    cout << fixed << setprecision(9);

    int n;
    while ((n=readUInt()) >= 0) {
        double
            w = readUInt(), // lane width
            u = readUInt(), // ships speed
            v = readUInt(), // ferry speed
            t1 = readUInt(),
            t2 = readUInt(),
            lct = w / v; // lane cross time

        vector<Event> vec;
        for (int i=0; i<n; ++i) {
            double offset = i * lct;

            char dir = readNonBlankChar();
            int m = readUInt();
            while (m--) {
                int l = readUInt(),
                    p = readInt();
                if (dir == 'E') p = -p;
                if (p >= 0) {
                    double st = -offset + p / u - lct,
                           ed = -offset + (p+l) / u;

                    if ((st>=t1 && st<=t2) || (ed>=t1 && ed<=t2)) {
                        vec.push_back(Event(st, 1));
                        vec.push_back(Event(ed, 0));
                    }
                }
            }
        }

        vec.push_back(Event(t2, 1));
        sort(vec.begin(), vec.end());
        double d = vec[0].time - t1;

        int inq = 0;
        for (int i=0, sz=vec.size(); i+1<sz && vec[i].time<t2; ++i) {
            if (vec[i].tp) ++inq;
            else --inq;
            if (inq == 0)
                d = max(d, vec[i+1].time - max(vec[i].time, t1));
        }
        cout << d << endl;
    }
}
