/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 599
  Name: The Forrest for the Trees
  Problem: https://onlinejudge.org/external/5/599.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

bool seen[30];
char gid[30], tmp[30];
char find(char u) {
    if (gid[u]==u) return u;

    int i=0;
    for(; u!=gid[u]; u=gid[u])
        tmp[i++] = u;

    for (int j=0; j<i; ++j)
        gid[tmp[j]] = u;

    return u;
}

void join(char u, char v) { gid[find(u)] = find(v); }
void intiDs() { for (int i=0; i<26; ++i) gid[i]=i; }


int main(){
    int T;
    char line[1000];
    scanf("%d", &T);
    while (getchar()!='\n');

    intiDs();
    while (true) {
        cin.getline(line, 1000);
        if (line[0]!='*') join(line[1]-'A', line[3]-'A');
        else {
            memset(seen, 0, 26);
            cin.getline(line, 1000);

            int acs=0, tcn=0;
            for (int i=0; line[i]; i+=2) {
                char u = line[i]-'A';
                if (gid[u]==u) ++acs;
                else {
                    u = find(u);
                    if (!seen[u]) {
                        seen[u] = 1;
                        ++tcn;
                    }
                }
                if (!line[i+1]) break;
            }

            printf("There are %d tree(s) and %d acorn(s).\n", tcn, acs-tcn);
            if (--T == 0) break;
            intiDs();
        }
    }
}
