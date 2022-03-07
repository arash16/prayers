/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10992
  Name: The Ghost of Programmers
  Problem: https://onlinejudge.org/external/109/10992.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

char names[9][50] = {
    "Tanveer Ahsan",
    "Shahriar Manzoor",
    "Adrian Kugel",
    "Anton Maydell",
    "Derek Kisman",
    "Rezaul Alam Chowdhury",
    "Jimmy Mardell",
    "Monirul Hasan",
};
int ds[11] = { 2, 5, 7, 11, 15, 20, 28, 36, 4, 100, 400 }, rs[11];
int parseInt(const char s[]) {
    int r = 0;
    for (int i=0; s[i]; i++)
        r = r*10 + s[i] - '0';
    return r;
}


int main(){
    char x[100];
    bool frst = 1;
    while (scanf("%s", x)==1 && (x[1] || x[0]!='0')) {
        if (frst) frst = 0;
        else putchar('\n');
        printf("%s\n", x);

        bool noGhost = 1;
        if (x[1] && x[2] && x[3] && (x[4] || parseInt(x) >= 2148)) {
            memset(rs, 0, sizeof(rs));
            for (int i=0; x[i]; i++)
                for (int j=0; j<11; j++)
                    rs[j] = (rs[j]*10 + x[i] - '0') % ds[j];

            for (int i=0; i<8; i++)
                if ((rs[i]-2148) % ds[i] == 0) {
                    printf("Ghost of %s!!!\n", names[i]);
                    noGhost = 0;
                }

            if ((!rs[8] && rs[9]) || !rs[10]) {
                puts("Ghost of K. M. Iftekhar!!!");
                noGhost = 0;
            }
        }

        if (noGhost)
            puts("No ghost will come in this year");
    }
}
