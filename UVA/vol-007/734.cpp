/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 734
  Name: The Programmer's Hex
  Problem: https://onlinejudge.org/external/7/734.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


string H[7], H2[7], tsq;
string normalize(const string &s) {
    string res = s;
    for (int i=1; i<6; ++i)
        res = min(res, s.substr(i, 6-i) + s.substr(0, i));

    return res;
}

int ID[7], P[7], R[7];
bool used[7];
bool bt(int peg, int le=0) {
    if (peg == 7) return le == H[P[1]][ ( R[1] + 4 )%6 ];

    int midE = H[P[0]][peg-1];
    bool seenid[7] = {};
    for (int i=0; i<7; ++i)
        if (!used[i] && !seenid[ID[i]]) {
            P[peg] = i;
            used[i] = 1;
            seenid[ID[i]] = 1;

            bool seen[10] = {};
            for (int j=0; j<6; ++j) {
                if (H[i][ (j + peg + 2)%6 ] == midE && (!le || H[i][ (j + peg + 3)%6 ] == le)) {
                    int nle = H[i][ (j + peg + 1)%6 ];
                    if (!le || !seen[nle-'0']) {
                        seen[nle-'0'] = 1;
                        R[peg] = j;
                        if (bt(peg+1, nle))
                            return 1;
                    }
                }
            }
            used[i] = 0;
        }
    return 0;
}


bool solve() {
    bool seenid[7] = {};
    memset(used, 0, sizeof(used));
    for (int i=0; i<7; ++i)
        if (!seenid[ID[i]]) {
            P[0] = i;
            used[i] = 1;
            seenid[ID[i]] = 1;
            if (bt(1)) return 1;
            used[i] = 0;
        }
    return 0;
}

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> H[0]) {
        for (int i=1; i<7; ++i)
            cin >> H[i];
        cin >> tsq;

        int sz = 0;
        for (int i=0; i<7; ++i) {
            H2[i] = normalize(H[i]);
            ID[i] = -1;
            for (int j=0; j<i; ++j)
                if (H2[i] == H2[j]) {
                    ID[i] = ID[j];
                    break;
                }
            if (ID[i] < 0) ID[i] = sz++;
        }

        if (solve()) {
            cout << "PEG   HEX   POSITION\n---   ---   --------\n";
            for (int i=0; i<7; ++i)
                cout << ' ' << i << "     "
                     << char('A' + P[i]) << "     "
                     << H[P[i]].substr(R[i], 6-R[i]) << H[P[i]].substr(0, R[i])
                     << '\n';
        }
        else cout << "No solution possible\n";
        cout << "************************************\n";
    }
}
