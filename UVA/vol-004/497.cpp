/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 497
  Name: Strategic Defense Initiative
  Problem: https://onlinejudge.org/external/4/497.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

/* Finds longest strictly increasing subsequence. O(n log k) algorithm. */
vector<int> find_lis(vector<int> &a)
{
    vector<int> b, p(a.size());
    int u, v;

    if (a.size() < 1) return b;

    b.push_back(0);

    for (size_t i = 1; i < a.size(); i++) {
        if (a[b.back()] < a[i]) {
            p[i] = b.back();
            b.push_back(i);
            continue;
        }

        for (u = 0, v = b.size()-1; u < v;) {
            int c = (u + v) / 2;
            if (a[b[c]] < a[i]) u=c+1; else v=c;
        }

        if (a[i] < a[b[u]]) {
            if (u > 0) p[i] = b[u-1];
            b[u] = i;
        }
    }

    for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;
    return b;
}


#include <cstdio>
int main()
{
    int T,n,i,t;
    char s[20];
    vector<int> seq,lis;

    scanf("%d\n\n",&T);
    while(T--){
        n=0;
        seq.clear();
        lis.clear();

        while(gets(s) && s[0]){
            sscanf(s,"%d",&t);
            seq.push_back(t);
            n++;
        }
        lis=find_lis(seq);
        printf("Max hits: %d\n",lis.size());
        for(i=0;i<lis.size();i++)
            printf("%d\n",seq[lis[i]]);
        if(T)
            printf("\n");
    }
    return 0;
}