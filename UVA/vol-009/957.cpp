/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 957
  Name: Popes
  Problem: https://onlinejudge.org/external/9/957.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int X[100001];
int main(){
    int n, y, si, bsi, bei;
    while (cin>>y>>n) {
        cin>>X[0];
        si=bsi=bei=0;
        for (int ei=1; ei<n; ei++) {
            cin>>X[ei];

            while (X[ei] - X[si] >= y)
                si++;

            if (ei-si > bei-bsi) {
                bsi = si;
                bei = ei;
            }
        }
        printf("%d %d %d\n", bei-bsi+1, X[bsi], X[bei]);
    }
}
