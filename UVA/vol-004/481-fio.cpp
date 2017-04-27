#include <stdio.h>
#include <iostream>
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
inline bool readInt(int &r) {
    char ch;
    int sgn=1;
    while (!isdigit(ch=readchar()) && ch!='-')
        if (ch == EOF) return 0;
    r = 0;
    if (ch == '-') sgn = -1;
    else r = ch-'0';
    while (isdigit(ch=readchar()))
        r = (r<<3) + (r<<1) + ch-'0';
    r*=sgn;
    return 1;
}

// ----------------------------------------------------------------


#define MAXN 100000
int n, X[MAXN], M[MAXN], P[MAXN], S[MAXN];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (n=0; readInt(X[n]) ; n++);
    int l = 0;
    for (int i=0; i<n; i++) {
        int lo=1, hi=l;
        while (lo<=hi) {
            int mid = (lo+hi+1)>>1;
            if (X[M[mid]] < X[i])
                lo = mid+1;
            else
                hi = mid-1;
        }

        P[i] = M[lo-1];
        M[lo] = i;
        if (lo > l) l = lo;
    }


    int k = M[l];
    for (int i=l-1; i>=0; i--) {
        S[i] = X[k];
        k = P[k];
    }

    cout << l << "\n-\n";
    for (int i=0; i<l; i++)
        cout << S[i] << endl;
}
