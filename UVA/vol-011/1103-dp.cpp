/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1103
  Name: Ancient Messages
  Problem: https://onlinejudge.org/external/11/1103.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int C[212][212], htoi[127], sz[55555], h, w;
char hexb[16][4], itoh[]="0123456789abcdef", hname[]="WAKJSD", out[55555];

bool B[212][212];
int di[]={0,1,0,-1}, dj[]={1,0,-1,0};
void dfill(int i, int j, int c) {
    if (C[i][j]) return;
    C[i][j] = c;

    bool cc = B[i][j];
    for (int k=0; k<4; ++k) {
        int ni=i+di[k], nj=j+dj[k];
        if (ni>=0 && ni<h && nj>=0 && nj<w && B[ni][nj]==cc)
            dfill(ni, nj, c);
    }
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=0; i<16; ++i) {
        htoi[itoh[i]] = i;
        for (int j=0; j<4; ++j)
            hexb[i][3-j] = (i & (1<<j)) != 0;
    }


    for (int cse=1; cin>>h>>w && (h||w); ++cse) {
        w <<= 2;
        for (int i=0; i<h; ++i) {
            memset(C[i], 0, w*sizeof(int));
            char s[60]; cin >> s;
            for (int j=0; s[j]; ++j)
                memcpy(&B[i][j<<2], hexb[htoi[s[j]]], 4);
        }

        for (int i=0; i<h; ++i) {
            if (!B[i][0] && !C[i][0])
                dfill(i, 0, -1);
            if (!B[i][w-1] && !C[i][w-1])
                dfill(i, w-1, -1);
        }
        for (int j=0; j<w; ++j) {
            if (!B[0][j] && !C[0][j])
                dfill(0, j, -1);
            if (!B[h-1][j] && !C[h-1][j])
                dfill(h-1, j, -1);
        }


        int lc = 0, lst;
        for (int i=0; i<h; ++i)
            for (int j=0; j<w; ++j)
                if (B[i][j]) {
                    if (!C[i][j]) {
                        sz[++lc] = 0;
                        dfill(i, j, lc);
                    }
                    lst = C[i][j];
                }
                else if (!C[i][j]) {
                    ++sz[lst];
                    dfill(i, j, -1);
                }

        out[lc] = 0;
        for (int i=0; i<lc; ++i)
            out[i] = hname[sz[i+1]];
        sort(out, out+lc);
        cout << "Case " << cse << ": " << out << endl;
    }
}
