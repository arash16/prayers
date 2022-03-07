/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10818
  Name: Dora Trip
  Problem: https://onlinejudge.org/external/108/10818.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


struct State {
    int i, j;
    State(int i, int j):i(i),j(j){}
};

char M[23][23];
int I[23][23], Sy[13], Sx[13], sz;
string D[23][23], bestp;

char dc[] = "ESNW";
int di[] = {0,1,-1,0},
    dj[] = {1,0,0,-1},
    dk[128];
void bfs(int sy, int sx, string D[]) {
    for (int i=0; i<sz; ++i)
        D[i] = "";

    char P[23][23] = {};
    queue<State> q;
    q.push(State(sy, sx));
    P[sy][sx] = -1;
    while (!q.empty()) {
        State s = q.front(); q.pop();
        if (M[s.i][s.j] == '*' || M[s.i][s.j] == 'S') {
            string r;
            for (int i=s.i,j=s.j; P[i][j]!=-1; ) {
                char ch = P[i][j];
                r = ch + r;
                i -= di[ dk[ch] ];
                j -= dj[ dk[ch] ];
            }
            D[I[s.i][s.j]] = r;
        }

        for (int k=0; k<4; ++k) {
            State t(s.i+di[k], s.j+dj[k]);
            if (!P[t.i][t.j]) {
                char ch = M[t.i][t.j];
                if (ch!='X' && ch!='#') {
                    P[t.i][t.j] = dc[k];
                    q.push(t);
                }
            }
        }
    }
}


int Mno[23];
bool visited[23];
int H() {
    int sum = 0;
    for (int i=0; i<sz; ++i)
        if (!visited[i])
            sum += Mno[i];
    return sum;
}

int P[23], bestl;
void bt(int li, int len, int cnt, int pi=0) {
    if (len + H() > bestl) return;
    if (cnt == sz) {
        int nlen = len+D[li][0].length();
        if (bestl >= nlen) {
            string np;
            int ci = 0;
            for (int i=0; i<pi; ++i)
                np += D[ci][P[i]],
                ci = P[i];
            np += D[ci][0];

            if (nlen < bestl || np < bestp) {
                bestl = nlen;
                bestp = np;
            }
        }
        return;
    }

    for (int i=1; i<sz; ++i)
        if (!visited[i] && D[li][i].length()) {
            P[pi] = i;
            visited[i] = 1;
            bt(i, len + D[li][i].length(), cnt+1, pi+1);
            visited[i] = 0;
        }
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=0; i<4; ++i)
        dk[dc[i]] = i;

    int r, c;
    while (cin >> r >> c && (r||c)) {
        sz = 1;
        cin.ignore(100, '\n');
        for (int i=0; i<r; ++i) {
            cin.getline(M[i], 23);
            for (int j=0; j<c; ++j)
                if (M[i][j] == '*')
                    Sy[sz] = i,
                    Sx[sz] = j,
                    I[i][j] = sz,
                    ++sz;
                else if (M[i][j] == 'S')
                    Sy[0] = i,
                    Sx[0] = j,
                    I[i][j] = 0;
                else
                    I[i][j] = -1;
        }

        for (int i=0; i<sz; ++i) {
            bfs(Sy[i], Sx[i], D[i]);
            Mno[i] = (int)1e9;
            for (int j=0; j<sz; ++j)
                if (D[i][j].length())
                    Mno[i] = min(Mno[i], (int)D[i][j].length());
        }

        int seent = 1;
        for (int i=1; i<sz; ++i) {
            visited[i] = !D[0][i].length();
            seent += visited[i];
        }

        if (seent == sz)
            cout << "Stay home!\n";
        else {
            bestp = "";
            bestl = (int)1e8;
            bt(0, 0, seent);
            cout << bestp << '\n';
        }
    }
}
