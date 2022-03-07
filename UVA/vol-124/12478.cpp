/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12478
  Name: Hardest Problem Ever (Easy)
  Problem: https://onlinejudge.org/external/124/12478.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


char G[10][10] = {
    "OBIDAIBKR",
    "RKAULHISP",
    "SADIYANNO",
    "HEISAWHIA",
    "IRAKIBULS",
    "MFBINTRNO",
    "UTOYZIFAH",
    "LEBSYNUNE",
    "EMOTIONAL"
},
names[10][10] = {
    "RAKIBUL",
    "ANINDYA",
    "MOSHIUR",
    "SHIPLU",
    "OBAIDA",
    "KABIR",
    "SUNNY",
    "WASI"
};

bool match(int ii, int jj, int F[], int l) {
    if (9-ii >= l) {
        int C[100] = {};
        for (int i=0; i<l; ++i)
            ++C[G[ii+i][jj]];
        if (memcmp(C, F, sizeof(C)) == 0)
            return 1;
    }
    if (9-jj >= l) {
        int C[100] = {};
        for (int j=0; j<l; ++j)
            ++C[G[ii][jj+j]];
        if (memcmp(C, F, sizeof(C)) == 0)
            return 1;
    }
    return 0;
}


bool check(char s[]) {
    int F[100] = {}, l;
    for (l=0; s[l]; ++l)
        ++F[s[l]];

    int cnt = 0;
    for (int i=0; i<9; ++i)
        for (int j=0; j<9; ++j)
            if (match(i, j, F, l) && ++cnt == 2)
                return 1;
    return 0;
}



int main() {
    for (int i=0; i<8; ++i)
        if (check(names[i])) {
            cout << names[i] << endl;
            return 0;
        }
}
