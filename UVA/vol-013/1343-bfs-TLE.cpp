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

#define MAXS 1048576
int TP[MAXS] = {1, 2, 3}, sz;
bool X[MAXS][24];

// 235968
int finY = (1 <<  6) | (1 <<  7)
         | (1 <<  8) | (1 << 11)
         | (1 << 12) | (1 << 15)
         | (1 << 16) | (1 << 17);
bool isFin(int state) { return (state&finY) == finY; }

int calcY(const bool XX[]) {
    int r = 0;
    for (int i=0; i<24; ++i)
        r = (r<<1) | XX[i];
    return r;
}

void moveForward(bool XX[], int k) {
    bool t = XX[moves[k][0]];
    for (int j=0; j<6; ++j)
        XX[moves[k][j]] = XX[moves[k][j+1]];
    XX[moves[k][6]] = t;
}

void moveBackward(bool XX[], int k) {
    bool t = XX[moves[k][6]];
    for (int j=6; j>0; --j)
        XX[moves[k][j]] = XX[moves[k][j-1]];
    XX[moves[k][0]] = t;
}


int S[1<<24], P[1<<24];
string BFS(int cse) {
    for (sz = 0; sz < 3; ++sz) {
        int state = calcY(X[sz]);
        if (isFin(state))
            return "No moves needed";
        S[state] = cse;
    }

    queue<int> q, qd;
    q.push(3);
    qd.push(0);

    for (int s=0; !q.empty();) {
        int l = q.front(); q.pop();
        int d = qd.front(); qd.pop();

        for (int k=0; k<8; ++k) {
            for (int i=s; i<l; ++i) {
                bool *XX = X[sz];
                memcpy(XX, X[i], 24);
                moveForward(XX, k);
                int state = calcY(XX);

                if (S[state]!= cse) {
                    S[state] = cse;
                    P[state] = k;
                    TP[sz] = TP[i];
                    if (isFin(state)) {
                        string result;
                        for (int j=0; j<=d; ++j) {
                            int state = calcY(XX);
                            result = char('A' + P[state]) + result;
                            moveBackward(XX, P[state]);
                        }
                        return result;
                    }
                    ++sz;
                }
            }
            q.push(sz);
            qd.push(d+1);
        }
        s = l;
    }
    return "";
}


int main() {
    int xx[24];
    for (int cse=1; cin>>xx[0] && xx[0]; ++cse) {
        for (int i=1; i<24; ++i)
            cin >> xx[i];

        for (int i=0; i<24; ++i) {
            X[0][i] = xx[i] == 1;
            X[1][i] = xx[i] == 2;
            X[2][i] = xx[i] == 3;
        }

        cout << BFS(cse) << '\n';
        cout << TP[sz] << '\n';
    }
}
