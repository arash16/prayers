/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10009
  Name: All Roads Lead Where?
  Problem: https://onlinejudge.org/external/100/10009.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <list>
using namespace std;

int T, n, q, par[26], asc[26][26];
char c1[100], c2[100];
int main(){
    cin>>T;
    while (T--) {
        cin >> n >> q;

        for (int i=0; i<n; i++) {
            cin>>c1>>c2;

            par[c2[0]-'A'] = c1[0]-'A';
            asc[c1[0]-'A'][c2[0]-'A']=1;
        }

        for (int k=0; k<26; k++) {
            asc[k][k]=1;
            for (int i=0; i<26; i++)
            if (asc[i][k])
                for (int j=0; j<26; j++)
                if (asc[k][j])
                    asc[i][j]=1;
        }

        for (int i=0; i<q; i++) {
            cin>>c1>>c2;
            int j, u=c1[0]-'A', v=c2[0]-'A';
            for (j=u; !asc[j][v]; j=par[j])
                putchar('A' + j);
            putchar('A'+j);
            list<int> ll;
            for (int k=v; k!=j; k=par[k])
                ll.push_front(k);

            for (int j: ll) putchar('A' + j);
            putchar('\n');
        }

        if (T) {
            memset(asc, 0, sizeof(asc));
            putchar('\n');
        }
    }
}
