/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12086
  Name: Potentiometers
  Problem: https://onlinejudge.org/external/120/12086.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>

inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf)
            return EOF;
        p = buf;
    }
    return *p++;
}

inline char readCh() {
    char ch;
    while ((ch=readchar())==' ' || ch=='\n');
    return ch;
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

char buf[50];
void print(long long x) {
    int i=48, neg=0;
    buf[i--] = '\n';
    if (!x) buf[i--] = '0';
    else if (x < 0) {
        x = -x;
        neg = 1;
    }
    for (; x; x/=10)
        buf[i--] = x%10 + '0';

    if (neg) buf[i--] = '-';
    fwrite_unlocked(buf+i+1, 1, 48-i, stdout);
}

// ------------------------------------------------------------------------

#define LSB(i) ((i) & -(i))

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

// ------------------------------------------------------------------------

int X[200017], B[200017];
int main() {
    bool frst = 1;
    int n, cse = 1;
    while ((n=readUInt())) {
        if (frst) frst = 0;
        else putchar('\n');
        printf("Case %d:\n", cse++);

        for (int i=0; i<n; ++i)
            X[i] = B[i] = readUInt();

        init(B, n);

        for (char cm; (cm=readCh()) != 'E'; ) {
            int x = readUInt() - 1,
                y = readUInt();

            if (cm == 'S') {
                update(B, n, x, y - X[x]);
                X[x] = y;
            }
            else print(getRange(B, x, y));
        }
        readchar(); readchar();
    }
}
