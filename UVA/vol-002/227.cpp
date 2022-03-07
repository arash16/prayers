/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 227
  Name: Puzzle
  Problem: https://onlinejudge.org/external/2/227.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

inline int readchar(bool skip=true) {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    static bool fin = 0;
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

inline char readSingleChar() {
    char ch;
    while ((ch=readchar())=='\n');
    return ch;
}

void skipLine() {
    while (readchar(0)!='\n')
        readchar();
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char G[5][5], ch;
    for (int cse=1; ;++cse) {
        int ii, jj;
        for (int i=0; i<5; ++i) {
            for (int j=0; j<5; ++j)
                if ((G[i][j] = readSingleChar()) == EOF)
                    return 0;
                else if (G[i][j] == ' ')
                    ii = i, jj = j;
            skipLine();
        }

        if (cse > 1) cout << '\n';
        cout << "Puzzle #" << cse << ":\n";

        bool valid = true;
        while ((ch=readSingleChar()) != '0')
            switch (ch) {
                case 'A':
                    if (!ii) valid = false;
                    else {
                        swap(G[ii][jj], G[ii-1][jj]);
                        --ii;
                    }
                    break;
                case 'B':
                    if (ii==4) valid = false;
                    else {
                        swap(G[ii][jj], G[ii+1][jj]);
                        ++ii;
                    }
                    break;
                case 'L':
                    if (!jj) valid = false;
                    else {
                        swap(G[ii][jj], G[ii][jj-1]);
                        --jj;
                    }
                    break;
                case 'R':
                    if (jj==4) valid = false;
                    else {
                        swap(G[ii][jj], G[ii][jj+1]);
                        ++jj;
                    }
                    break;
                default:
                    valid = false;
            }

        if (!valid)
            cout << "This puzzle has no final configuration.\n";

        else {
            for (int i=0; i<5; ++i) {
                cout << G[i][0];
                for (int j=1; j<5; ++j)
                    cout << ' ' << G[i][j];
                cout << '\n';
            }
        }
    }
}
