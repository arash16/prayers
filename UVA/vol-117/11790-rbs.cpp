/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11790
  Name: Murcia's Skyline
  Problem: https://onlinejudge.org/external/117/11790.pdf
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

// -----------------------------------------------------------------------

int Y[10000043], mxw;
void assignRange(int rl, int rr, int val, int rest=-1, int sl=0, int sr=mxw, int si=0) {
    if (rl<=sl && rr>=sr) Y[si] = val;
    if (Y[si] == val) return;
    if (rl>=sr || rr<=sl) {
        if (rest != -1)
            Y[si] = rest;
        return;
    }

    int id1 = (si<<1) + 1, id2 = (si<<1) + 2;
    if (Y[si] != -1)
        Y[id1] = Y[id2] = Y[si];

    int cval = rest!=-1 ? rest : Y[si];
    int mid = (sl + sr) >> 1;
    assignRange(rl, rr, val, cval, sl, mid, id1);
    assignRange(rl, rr, val, cval, mid, sr, id2);
    Y[si] = Y[id1]==Y[id2] ? Y[id1] : -1;
}

int getPoint(int ind, int sl=0, int sr=mxw, int si=0) {
    if (Y[si] >= 0) return Y[si];
    int mid = (sl + sr) >> 1;
    return ind < mid
        ? getPoint(ind, sl, mid, (si<<1)+1)
        : getPoint(ind, mid, sr, (si<<1)+2);
}



int H[10043], W[10043], n;
int LIS(bool comp(int, int)) {
    int L = Y[0] = 0;
    for (int i=0; i<n; ++i) {
        int lo = 1,
            hi = L;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1,
                mmi = getPoint(mid);
            if (comp(H[mmi], H[i]))
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        assignRange(lo, lo+W[i], i);
        L = max(L, lo+W[i]-1);
    }

    return L;
}

bool isLt(int a, int b) { return a < b; }
bool isGt(int a, int b) { return a > b; }

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T = readUInt();;
    for (int cse=1; cse<=T; ++cse) {
        n = readUInt();
        for (int i=0; i<n; ++i)
            H[i] = readUInt();

        mxw = 10;
        for (int j=0; j<n; ++j)
            mxw += (W[j] = readUInt());

        int incr = LIS(isLt),
            decr = LIS(isGt);

        cout << "Case " << cse << ".";
        if (incr >= decr) {
            cout << " Increasing (" << incr << ").";
            cout << " Decreasing (" << decr << ").";
        }
        else {
            cout << " Decreasing (" << decr << ").";
            cout << " Increasing (" << incr << ").";
        }
        cout << "\n";
    }
}
