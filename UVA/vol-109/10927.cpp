#include <bits/stdc++.h>
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

// --------------------------------------------------------------------------------------

#define EPS 1e-16
double A[100143];
long long R[100143];
int I[100143], J[100143], X[100143], Y[100143], L[100143];

bool comp2(int i, int j) { return X[i]==X[j] ? Y[i] < Y[j] : X[i] < X[j]; }
bool same(int i, int j) { return X[i]*Y[j] == X[j]*Y[i]; }
bool comp1(int i, int j) {
    int xy1 = X[i]*Y[j], xy2 = X[j]*Y[i];
    return xy1==xy2 ? R[i] < R[j] : xy1 < xy2;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    for (int cse=1; (n=readInt())>0; ++cse) {
        for (int i=0; i<n; ++i) {
            X[i] = readInt();
            Y[i] = readInt();
            L[i] = readInt();
            R[i] = ((long long) X[i]) * X[i] + Y[i]*Y[i];
            I[i] = i;
        }
        sort(I, I+n, comp1);

        int sz = 0, li = I[0], ll = L[li];
        for (int i=1; i<n; ++i) {
            int u = I[i];
            if (same(u, li) && L[u] <= ll)
                J[sz++] = u;
            else ll = L[u];
            li = u;
        }

        cout << "Data set " << cse << ":\n";
        if (!sz) cout << "All the lights are visible.\n";
        else {
            cout << "Some lights are not visible:\n";
            sort(J, J+sz, comp2);
            for (int i=0; i<sz; ++i) {
                cout << "x = " << X[J[i]] << ", y = " << Y[J[i]];
                cout << (i==sz-1 ? ".\n" : ";\n");
            }
        }
    }
}
