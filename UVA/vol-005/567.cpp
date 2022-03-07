/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 567
  Name: Risk
  Problem: https://onlinejudge.org/external/5/567.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define INF 10000000

int main(){
    int cse = 1, d[22][22], x, y, q, n;
    for(;;) {
        for (int i=1; i<=20; i++) {
            d[i][i] = 0;
            for (int j=i+1; j<=20; j++)
                d[i][j]=d[j][i]=INF;
        }

        for (int i=1; i<20; i++)
            if (!(cin>>n)) return 0;
            else for (int j=0; j<n; j++) {
                cin>>x;
                d[i][x] = d[x][i] = 1;
            }

        for (int k=1; k<=20; k++)
            for (int i=1; i<=20; i++)
                for (int j=1; j<=20; j++)
                    if (d[i][k] + d[k][j] < d[i][j])
                        d[i][j] = d[i][k] + d[k][j];

        cout << "Test Set #" << (cse++) << endl;
        cin >> q;
        for (int i=0; i<q; i++) {
            cin>>x>>y;
            printf("%2d to %2d: %d\n", x, y, d[x][y]);
        }
        cout << endl;
    }
}
