/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11402
  Name: Ahoy, Pirates!
  Problem: https://onlinejudge.org/external/114/11402.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXS 4096000
int n;
char O[MAXS];
void assignRange(char Y[], int rl, int rr, int val, int rest=-1, int sl=0, int sr=n, int si=0) {
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
    assignRange(Y, rl, rr, val, cval, sl, mid, id1);
    assignRange(Y, rl, rr, val, cval, mid, sr, id2);
    Y[si] = Y[id1]==Y[id2] ? Y[id1] : -1;
}

void reverseRange(char Y[], int rl, int rr, int sl=0, int sr=n, int si=0) {
    if (rl<=sl && rr>=sr && Y[si]!=-1)
        { Y[si] ^= 1; return; }
    if (rl>=sr || rr<=sl) return;

    if (Y[si] != -1) {
        assignRange(Y, rl, rr, Y[si]^1, -1, sl, sr, si);
        return;
    }

    int id1 = (si<<1) + 1, id2 = (si<<1) + 2;
    int mid = (sl + sr) >> 1;
    reverseRange(Y, rl, rr, sl, mid, id1);
    reverseRange(Y, rl, rr, mid, sr, id2);
    Y[si] = Y[id1]==Y[id2] ? Y[id1] : -1;
}

int getSum(char Y[], int rl, int rr, int val=-1, int sl=0, int sr=n, int si=0) {
    if (sl>=sr || rl>=sr || sl>=rr) return 0;
    if (val< 0) val = Y[si];
    if (val>=0)
        return val ? min(sr, rr) - max(sl, rl) : 0;

    int id1 = (si<<1) + 1,
        id2 = (si<<1) + 2;
    int mid = (sl + sr) >> 1;
    return    getSum(Y, rl, rr, val, sl, mid, id1) +
            getSum(Y, rl, rr, val, mid, sr, id2);
}


int getPoint(char Y[], int ind, int sl=0, int sr=n, int si=0) {
    if (Y[si] >= 0) return Y[si];
    int mid = (sl + sr) >> 1;
    return ind < mid
        ? getPoint(Y, ind, sl, mid, (si<<1)+1)
        : getPoint(Y, ind, mid, sr, (si<<1)+2);
}


bool M[4096000];
void initialize(int sl=0, int sr=n, int si=0) {
    if (sl == sr-1) O[si] = M[sl];
    if (sl >= sr-1) return;

    int id1 = (si<<1)+1,
        id2 = (si<<1)+2,
        mid = (sl + sr) >> 1;
    initialize(sl, mid, id1);
    initialize(mid, sr, id2);
    O[si] = O[id1]==O[id2] ? O[id1] : -1;
}


void printRange(char Y[], int cc=-1) {
    for (int i=0; i<n; ++i) {
        if (i==cc) cout << '>';
        cout << getPoint(Y, i) << ' ';
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char cm;
    int T, m, c;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cout << "Case " << cse << ":\n";
        n = 0;
        for (cin>>c; c--; ) {
            string str;
            cin >> m >> str;
            for (int i=0; i<m; ++i)
                for (char ch: str)
                    M[n++] = ch-'0';
        }
        initialize();

        cin >> m;
        for (int i=0, q=0, s,e; i<m; ++i) {
            cin >> cm >> s >> e;
            if (cm == 'F')
                assignRange(O, s, e+1, 1);
            else if (cm == 'E')
                assignRange(O, s, e+1, 0);
            else if (cm == 'I')
                reverseRange(O, s, e+1);

            else
                cout << "Q" << (++q) << ": " << getSum(O, s, e+1) << endl;
        }
    }
}
