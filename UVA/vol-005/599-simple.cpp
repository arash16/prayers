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

int seen[200];
int main(){
    int T;
    char line[1000];
    scanf("%d", &T);
    while (getchar()!='\n');
    for (int cse=1; cse<=T; ++cse) {
        int ecn = 0;
        while (gets(line) && line[0]!='*') {
            seen[line[1]] = seen[line[3]] = cse;
            ++ecn;
        }

        gets(line);
        int acn=0, tcn=0;
        for (int i=0; ;i+=2) {
            ++tcn;
            if (seen[line[i]]!=cse) ++acn;
            if (!line[i+1]) break;
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tcn-ecn-acn, acn);
    }
}
