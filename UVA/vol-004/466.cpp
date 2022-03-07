/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 466
  Name: Mirror, Mirror
  Problem: https://onlinejudge.org/external/4/466.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

char msgs[9][100] = {
    "preserved",
    "rotated 90 degrees",
    "rotated 180 degrees",
    "rotated 270 degrees",
    "reflected vertically",
    "reflected vertically and rotated 90 degrees",
    "reflected vertically and rotated 180 degrees",
    "reflected vertically and rotated 270 degrees",
    "improperly transformed"
};

int n;
char X[20][20], Y[20][20], tmp[20][20];

void rotate() {
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            tmp[j][n-i-1] = X[i][j];
    swap(X, tmp);
}

void mirror() {
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            tmp[n-i-1][j] = X[i][j];
    swap(X, tmp);
}

bool pequal() {
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (X[i][j] != Y[i][j])
                return 0;
    return 1;
}

int analyse() {
    for (int i=0; i<2; ++i) {
        for (int j=0; j<4; ++j) {
            if (pequal())
                return i*4 + j;
            rotate();
        }
        mirror();
    }
    return 8;
}

int main() {
    for (int cse=1; scanf("%d", &n)==1; ++cse) {
        for (int i=0; i<n; ++i)
            scanf("%s%s", X[i], Y[i]);

        printf("Pattern %d was %s.\n", cse, msgs[analyse()]);
    }
}
