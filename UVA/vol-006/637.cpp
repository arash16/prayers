/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 637
  Name: Booklet Printing
  Problem: https://onlinejudge.org/external/6/637.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


void printPage(int p) {
    if (p) cout << p;
    else cout << "Blank";
}

int main() {
    int n;
    while (cin >> n && n) {
        printf("Printing order for %d pages:\n", n);

        int P[143][4] = {},
            sz = (n+3)/4,
            p=0, i;

        for (i=0; i<sz; ++i)
            P[i][0] = ++p,
            P[i][1] = ++p;

        for (--i; p<n; --i)
            P[i][2] = ++p,
            P[i][3] = ++p;

        for (int i=0; i<sz; ++i) {
            for (int j=0; j<4; ++j)
                if (P[i][j] > n)
                    P[i][j] = 0;

            if (P[i][3] || P[i][0]) {
                printf("Sheet %d, front: ", i+1);
                printPage(P[i][3]);
                cout << ", ";
                printPage(P[i][0]);
                cout << endl;
            }

            if (P[i][1] || P[i][2]) {
                printf("Sheet %d, back : ", i+1);
                printPage(P[i][1]);
                cout << ", ";
                printPage(P[i][2]);
                cout << endl;
            }
        }
    }
}
