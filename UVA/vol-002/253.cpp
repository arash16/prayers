/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 253
  Name: Cube painting
  Problem: https://onlinejudge.org/external/2/253.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int rots[3][4] = {
    {1, 2, 4, 3},
    {0, 3, 5, 2},
    {0, 1, 5, 4}
};

bool check(char *u, char *v) {
    for (int i=0; i<3; i++)
        for (int j=i; j<3; j++) {
            int *r1 = rots[i],
                *r2 = rots[j];

            if (u[i]==v[j] && u[5-i]==v[5-j]) {
                for (int k=0; k<4; k++)
                    if (u[r1[0]]==v[r2[(k+0)%4]] &&
                        u[r1[1]]==v[r2[(k+1)%4]] &&
                        u[r1[2]]==v[r2[(k+2)%4]] &&
                        u[r1[3]]==v[r2[(k+3)%4]])
                            return true;
            }
            else if (u[i]==v[5-j] && u[5-i]==v[j]) {
                for (int k=0; k<4; k++)
                    if (u[r1[0]]==v[r2[(k+3)%4]] &&
                        u[r1[1]]==v[r2[(k+2)%4]] &&
                        u[r1[2]]==v[r2[(k+1)%4]] &&
                        u[r1[3]]==v[r2[(k+0)%4]])
                            return true;
            }
        }
    return false;
}

int main(){
    char w[20];
    while (cin>>w)
        puts(check(w,w+6) ? "TRUE" : "FALSE");
}
