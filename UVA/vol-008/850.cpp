/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 850
  Name: Crypt Kicker II
  Problem: https://onlinejudge.org/external/8/850.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

char fox[] = "the quick brown fox jumps over the lazy dog";
char m[128];
bool test(char line[]) {
    memset(m, 0, sizeof(m));

    for (int i=0; fox[i]; i++)
        if (fox[i]==' ' && line[i]!=' ')
            return false;
        else if (!m[line[i]])
            m[line[i]] = fox[i];
        else if (m[line[i]] != fox[i])
            return false;

    return true;
}


char lines[102][102];
int main(){
    int fen = strlen(fox);

    int T;
    cin>>T;
    cin.getline(lines[0], 102);
    cin.getline(lines[0], 102);

    while (T--) {
        int n = 0, i;
        while (cin.getline(lines[n], 102) && lines[n][0])
            n++;

        for (i=0; i<n; i++)
            if (strlen(lines[i]) == fen)
                if (test(lines[i]))
                    break;

        if (i==n) cout<<"No solution.\n";
        else for (int i=0; i<n; i++) {
                for(int j=0; lines[i][j]; j++)
                    if (m[lines[i][j]])
                        cout<<m[lines[i][j]];
                    else
                        cout<<lines[i][j];
                cout<<endl;
            }

        if (T) cout<<endl;
    }
}
