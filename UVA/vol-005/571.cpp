/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 571
  Name: Jugs
  Problem: https://onlinejudge.org/external/5/571.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

char actions[][30] = {
    "fill A",
    "fill B",
    "empty A",
    "empty B",
    "pour A B",
    "pour B A"
};

int cse=0, A, B, G, seen[1001][1001], path[1000000], plen;
bool dfs(int a, int b, int d) {
    if (seen[a][b] == cse) return false;
    if (a==G || b==G) {
        plen = d;
        return true;
    }
    seen[a][b] = cse;

    if (dfs(0, b, d+1)) {
        path[d] = 2;
        return 1;
    }

    if (dfs(a, 0, d+1)) {
        path[d] = 3;
        return 1;
    }

    if (a<=B-b ? dfs(0, b+a, d+1) : dfs(a+b-B, B, d+1)) {
        path[d] = 4;
        return 1;
    }

    if (b<=A-a ? dfs(b+a, 0, d+1) : dfs(A, a+b-A, d+1)) {
        path[d] = 5;
        return 1;
    }

    if (dfs(A, b, d+1)) {
        path[d] = 0;
        return 1;
    }

    if (dfs(a, B, d+1)) {
        path[d] = 1;
        return 1;
    }

    return false;
}


int main(){
    while (scanf("%d%d%d", &A, &B, &G)==3) {
        cse++;
        dfs(0, 0, 0);
        for (int i=0; i<plen; i++)
            puts(actions[path[i]]);
        puts("success");
    }
}
