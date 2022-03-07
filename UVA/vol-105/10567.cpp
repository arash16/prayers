/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10567
  Name: Helping Fill Bates
  Problem: https://onlinejudge.org/external/105/10567.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

char line[1000017],
     qs[3517][117],
     ch, nch;

int aw[127][3517], n,
    deg[127], index[3517],
    strt[3517], endd[3517];


int main(){
    cin>>line>>n;

    for (int i=0; i<n; i++) {
        cin>>qs[i]; ch=qs[i][0];
        aw[ch][deg[ch]++] = i;
        endd[i]=-1;
    }

    for (int k=0; (ch=line[k]); k++) {
        int j=deg[ch];
        deg[ch] = 0;
        for (int i=0; i<j; i++) {
            int qsi = aw[ch][i],
                ind = ++index[qsi];
            nch = qs[qsi][ind];

            if (ind == 1)
                strt[qsi] = k;
            if (!nch)
                endd[qsi] = k;
            else
                aw[nch][deg[nch]++] = qsi;
        }
    }

    for (int i=0; i<n; i++)
        if (endd[i] < 0)
            puts("Not matched");
        else
            printf("Matched %d %d\n", strt[i], endd[i]);
}
