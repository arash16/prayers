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

inline bool readStr(char *str) {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    if (ch == EOF) return 0;

    *str++ = ch;
    while ((ch=readchar())!=' ' && ch!='\n' && ch!=EOF)
        *str++ = ch;
    *str = 0;
    return 1;
}

// -------------------------------------------------------------------



struct State {
    int i, j, d;
    State(int i, int j, int d):i(i),j(j),d(d){}
};

int dy[] = {1,-1,0,0},
    dx[] = {0,0,1,-1};
bool S[1017][1017], B[1017][1017];


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char line[1017];
    int T = readUInt();
    while (T--) {
        int n = readUInt(),
            m = readUInt();

        queue<State> q1, q2;
        for (int i=0; i<n; ++i) {
            readStr(line);
            for (int j=0; j<m; ++j) {
                char ch = line[j];

                B[i][j] = ch=='#';
                if (ch == 'F') {
                    q2.push(State(i, j, 0));
                    B[i][j] = 1;
                }

                S[i][j] = ch!='.';
                if (ch == 'J')
                    q1.push(State(i, j, 0));
            }
        }

        for (int d=0; !q1.empty(); ++d) {
            while (!q1.empty()) {
                State s = q1.front();
                if (s.d > d) break;
                q1.pop();
                if (B[s.i][s.j]) continue;

                for (int k=0; k<4; ++k) {
                    State t(s.i+dy[k], s.j+dx[k], s.d+1);
                    if (t.i<0 || t.j<0 || t.i>=n || t.j>=m) {
                        cout << t.d << endl;
                        goto fin;
                    }
                    if (!S[t.i][t.j]) {
                        q1.push(t);
                        S[t.i][t.j] = 1;
                    }
                }
            }

            while (!q2.empty()) {
                State s = q2.front();
                if (s.d > d) break;
                q2.pop();

                for (int k=0; k<4; ++k) {
                    State t(s.i+dy[k], s.j+dx[k], s.d+1);
                    if (t.i<0 || t.j<0 || t.i>=n || t.j>=m)
                        continue;

                    if (!B[t.i][t.j]) {
                        q2.push(t);
                        B[t.i][t.j] =
                        S[t.i][t.j] = 1;
                    }
                }
            }
        }
        cout << "IMPOSSIBLE\n";
        fin:;
    }
}
