/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1343
  Name: The Rotation Game
  Problem: https://onlinejudge.org/external/13/1343.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int moves[8][7] = {
    { 0, 2, 6, 11, 15, 20, 22 },
    { 1, 3, 8, 12, 17, 21, 23 },
    { 10, 9, 8, 7, 6, 5, 4 },
    { 19, 18, 17, 16, 15, 14, 13 },
    { 23, 21, 17, 12, 8, 3, 1 },
    { 22, 20, 15, 11, 6, 2, 0 },
    { 13, 14, 15, 16, 17, 18, 19 },
    { 4, 5, 6, 7, 8, 9, 10}
};
int center[] = {6, 7, 8, 11, 12, 15, 16, 17};

void moveForward(char XX[], int k) {
    char t = XX[moves[k][0]];
    for (int j=0; j<6; ++j)
        XX[moves[k][j]] = XX[moves[k][j+1]];
    XX[moves[k][6]] = t;
}

int H(char X[]) {
    int cnt[3] = {};
    for (int i=0; i<8; ++i)
        ++cnt[X[center[i]]];
    return 8 - max(cnt[0], max(cnt[1], cnt[2]));
}


int path[20], maxd;
bool IDAS (char X[], int d) {
    int hv = H(X); // minimum remaining moves
    if (!hv) {
        if (!d) cout << "No moves needed\n";
        else {
            for (int i=0; i<d; ++i)
                cout << char('A' + path[i]);
            cout << '\n';
        }
        cout << X[6]+1 << '\n';
        return 1;
    }

    if (d + hv > maxd) return 0;

    char Y[24];
    for (int k=0; k<8; ++k) {
        path[d] = k;
        memcpy(Y, X, 24);
        moveForward(Y, k);
        if (IDAS(Y, d+1))
            return 1;
    }
    return 0;
}


int main() {
    int xx[24];
    char X[24];
    for (int cse=1; cin>>xx[0] && xx[0]; ++cse) {
        for (int i=1; i<24; ++i)
            cin >> xx[i];

        for (int i=0; i<24; ++i)
            X[i] = xx[i] - 1;

        bool solved = 0;
        for (maxd=1; !solved; ++maxd)
            solved |= IDAS(X, 0);
    }
}
