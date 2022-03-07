/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11860
  Name: Document Analyzer
  Problem: https://onlinejudge.org/external/118/11860.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

#define MAXN 100001
int seen[MAXN], X[MAXN];

int main(){
    int T;
    scanf("%d", &T);
    for (int cse=1; cse<=T; ++cse) {
        int un=0, tn=0;

        unordered_map<string, int> ids;
        char word[200]={0}, len=0;
        while (word[0] != 'E') {
            if (len) {
                auto it = ids.find(word);
                int id;
                if (it == ids.end()) {
                    id = ids[word] = un++;
                    seen[id] = 0;
                }
                else id = it->second;

                X[tn++] = id;
            }

            while (!isalpha(word[0]=getchar()));
            for(len=1; isalpha(word[len]=getchar()); ++len);
            word[len] = 0;
        }

        int bi=-1, bj=MAXN+1, run=0;
        for (int i=0,j=0; j<tn; ++j) {
            if (!seen[X[j]]++) run++;

            while (i<j && seen[X[i]]>1)
                --seen[X[i++]];

            if (run==un && j-i<bj-bi) {
                bj=j;
                bi=i;
            }
        }
        printf("Document %d: %d %d\n", cse, bi+1, bj+1);
    }
}
