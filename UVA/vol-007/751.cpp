/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 751
  Name: Triangle War
  Problem: https://onlinejudge.org/external/7/751.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

const int fstate = (1<<18) - 1;
int tcn[18],
    lid[10][10],
    ltr[18][2] = {
        {  0,  1 }, { 1,   2 },
        {  1,  5 }, { 3,   4 }, {  4,  5 },
        {  5,  6 }, { 6,   7 },
        {  4, 10 }, { 8,   9 }, {  9, 10 },
        {  6, 12 }, { 10, 11 }, { 11, 12 },
        { 12, 13 }, { 13, 14 },
        {  9, 15 }, { 11, 16 }, { 13, 17 },
    };

bool seen[262143];
int memo[262143];
int alphabeta(int state) {
    if (state == fstate) return 0;
    if (seen[state]) return memo[state];

    int bd = -10000;
    for (int i=0, msk=1; i<18; ++i, msk<<=1)
        if (!(state&msk)) {
            int t1 = ltr[i][0],
                t2 = ltr[i][1];
            ++tcn[t1]; ++tcn[t2];

            int t = alphabeta(state | msk);
            if (tcn[t1]!=3 && tcn[t2]!=3)
                 bd = max(bd, -t);
            else bd = max(bd, t + (tcn[t1]==3) + (tcn[t2]==3));

            --tcn[t1]; --tcn[t2];
        }

    seen[state] = 1;
    return memo[state] = bd;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=1,l=1,k=0; i<10; i+=l++)
        for (int j=i; j<i+l; ++j) {
            if (j+1 < i+l)
                lid[j][j+1] = k++;
            if (j < 7) {
                lid[j][j+l] = k++;
                lid[j][j+l+1] = k++;
            }
        }

    int T; cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        memset(tcn, 0, sizeof(tcn));

        int state=0, score[2]={};
        bool player=0;
        int m; cin >> m;
        for (int i=0, u, v; i<m; ++i) {
            cin >> u >> v;
            int id = lid[u][v];
            state |= 1<<id;


            ++tcn[ltr[id][0]]; ++tcn[ltr[id][1]];
            if (tcn[ltr[id][0]]!=3 && tcn[ltr[id][1]]!=3)
                player = !player;
            else {
                score[player] += tcn[ltr[id][0]]==3;
                score[player] += tcn[ltr[id][1]]==3;
            }
        }

        score[player] += alphabeta(state);
        cout << "Game " << cse << ": " << (score[0]>score[1] ? 'A' : 'B') << " wins.\n";
    }
}
