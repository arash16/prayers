/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 487
  Name: Boggle Blitz
  Problem: https://onlinejudge.org/external/4/487.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


#define MAXS 100143
char Pch[MAXS];
int S[MAXS][128], P[MAXS], scnt;
int nextState(int st, char ch) {
    if (!S[st][ch]) {
        int nst = S[st][ch] = scnt++;
        memset(S[nst], 0, 128*sizeof(int));
        Pch[nst] = ch;
        P[nst] = st;
    }

    if (scnt > MAXS) throw 1;
    return S[st][ch];
}

char M[21][21];
bool inside[21][21];
int seen[MAXS][21][21], cse, n;
void dfs(int st, int i, int j) {
    if (seen[st][i][j] == cse) return;
    seen[st][i][j] = cse;

    inside[i][j] = 1;

    char cch = M[i][j];
    for (int di=-1; di<2; ++di) {
        int ni = i+di;
        if (ni>=0 && ni<n)
        for (int dj=-1; dj<2; ++dj)
            if (di || dj) {
                int nj = j+dj;
                if (nj>=0 && nj<n && !inside[ni][nj] && M[ni][nj]>cch)
                    dfs(nextState(st, M[ni][nj]), ni, nj);
            }
    }

    inside[i][j] = 0;
}


int Q[MAXS];
char str[21*21];
void printAll() {
    int qz = 1, qi = 0;
    Q[0] = 0;
    for (int d=0; qi<qz; ++d) {
        str[d] = 0;
        int sz = qz;
        for (; qi<sz; ++qi) {
            int st = Q[qi];
            if (d > 2) {
                for (int i=d-1, kst=st; i>=0; --i)
                    str[i] = Pch[kst],
                    kst = P[kst];

                cout << str << endl;
            }

            for (int ch=1; ch<128; ++ch)
                if (S[st][ch])
                    Q[qz++] = S[st][ch];
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    for (cse=1; T-- && cin>>n; ++cse) {
        cin.ignore(100, '\n');
        for (int i=0; i<n; ++i)
            cin.getline(M[i], 21);

        scnt = 1;
        memset(S[0], 0, 128*sizeof(int));
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                dfs(nextState(0, M[i][j]), i, j);

        printAll();
        if (T) cout << endl;
    }
}
