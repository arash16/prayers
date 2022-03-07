/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 526
  Name: String Distance and Transform Process
  Problem: https://onlinejudge.org/external/5/526.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char s1[100], s2[100];
    int DP[100][100], P[100][100], i, j, c;
    for (int i=0; i<100; i++) {
        DP[0][i] = DP[i][0] = i;
        P[0][i] = 1; P[i][0] = 2;
    }

    bool frst = 1;
    while (cin.getline(s1+1, 99) && cin.getline(s2+1, 99)) {
        if (frst) frst = 0;
        else putchar('\n');

        for (i=1; s1[i]; i++)
            for (j=1; s2[j]; j++)
                if (s1[i] == s2[j]) {
                    DP[i][j] = DP[i-1][j-1];
                    P[i][j] = 3;
                }
                else if (DP[i][j-1] < DP[i-1][j] && DP[i][j-1] < DP[i-1][j-1]) {
                    DP[i][j] = DP[i][j-1] + 1;
                    P[i][j] = 1;
                }
                else if (DP[i-1][j] < DP[i-1][j-1]) {
                    DP[i][j] = DP[i-1][j] + 1;
                    P[i][j] = 2;
                }
                else {
                    DP[i][j] = DP[i-1][j-1] + 1;
                    P[i][j] = 3;
                }

        int id = 0;
        printf("%d\n", c = DP[--i][--j]);
        while (i || j) {
            if (P[i][j] == 1)
                printf("%d Insert %d,%c\n", ++id, i+1, s2[j--]);

            else if (P[i][j] == 2)
                printf("%d Delete %d\n", ++id, i--);

            else {
                if (s1[i] != s2[j])
                    printf("%d Replace %d,%c\n", ++id, i, s2[j]);
                --i; --j;
            }
        }
    }
}
