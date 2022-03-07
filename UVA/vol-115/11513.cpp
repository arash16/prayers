/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11513
  Name: 9 Puzzle
  Problem: https://onlinejudge.org/external/115/11513.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


char MovN[6][3] = {
    "H1", "H2", "H3",
    "V1", "V2", "V3"
};
int Mov[6][3] = {
    { 0, 1, 2 },
    { 3, 4, 5 },
    { 6, 7, 8 },
    { 6, 3, 0 },
    { 7, 4, 1 },
    { 8, 5, 2 }
};
int X[9];


struct State {
    char s[9];
    State(){}
    State(const State &t){ memcpy(s, t.s, 9); }
    int toInt() {
        int r = 0;
        for (int i=0; i<9; ++i)
            r = r*10 + s[i];
        return r;
    }
};

unordered_map<int, int> P;
void reverse_bfs() {
    State src;
    for (int i=0; i<9; ++i)
        src.s[i] = i;

    queue<State> q;
    q.push(src);
    P[src.toInt()] = -1;

    while (!q.empty()) {
        State s = q.front(); q.pop();

        for (int k=0; k<6; ++k) {
            State t(s);
            swap(t.s[Mov[k][0]], t.s[Mov[k][2]]);
            swap(t.s[Mov[k][0]], t.s[Mov[k][1]]);
            int vid = t.toInt();
            if (P.emplace(vid, k).second)
                q.push(t);
        }
    }
}


char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    reverse_bfs();

    State t;
    while (cin>>X[0]>>X[1]>>X[2]>>X[3]>>X[4]>>X[5]>>X[6]>>X[7]>>X[8]) {
        for (int i=0; i<9; ++i)
            t.s[i] = X[i]-1;

        auto it = P.find(t.toInt());
        if (it == P.end()) cout << "Not solvable\n";
        else {
            int d = 0;
            string result = "";
            for (int k=it->second; k!=-1; ++d) {
                swap(t.s[Mov[k][0]], t.s[Mov[k][1]]);
                swap(t.s[Mov[k][0]], t.s[Mov[k][2]]);
                result += MovN[k];
                k = P[t.toInt()];
            }

            cout << d << ' ' << result << '\n';
        }
    }
}
