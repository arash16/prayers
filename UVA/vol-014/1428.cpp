/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1428
  Name: Ping pong
  Problem: https://onlinejudge.org/external/14/1428.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
#define INF 268435456
#define LSB(i) ((i) & -(i))
using namespace std;

inline int readchar(bool skip=true) {
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
    int result = *p;
    if (skip) ++p;
    return result;
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

// ------------------------------------------------------------------------------


int X[20143], Bl[400143], Br[400143];
void init(int BIT[], int size) {
    for (int i = 0; i < size; ++i) {
        int j = i + LSB(i+1);

        if (j < size)
            BIT[j] += BIT[i];
    }
}

void update(int BIT[], int size, int i, int delta) {
    while (i < size) {
        BIT[i] += delta;
        i += LSB(i+1);
    }
}

// [i .. j-1]
int getRange(int BIT[], int i, int j) {
    int sum = 0;
    while (j > i) {
        sum += BIT[j-1];
        j -= LSB(j);
    }
    while (i > j) {
        sum -= BIT[i-1];
        i -= LSB(i);
    }
    return sum;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();
    while (T--) {
        int n = readUInt(), mx=0;
        for (int i=0; i<n; ++i) {
            ++Br[ X[i] = readUInt() ];
            mx = max(mx, X[i]+1);
        }
        memset(Bl, 0, 4*mx*sizeof(int));
        init(Br, mx);

        long long sum = 0;
        for (int i=0; i<n; ++i) {
            update(Br, mx, X[i], -1);

            sum += getRange(Bl, 0, X[i]+1) * getRange(Br, X[i], mx)
                +  getRange(Bl, X[i], mx) * getRange(Br, 0, X[i]+1);

            update(Bl, mx, X[i], +1);
        }
        cout << sum << "\n";
    }
}
