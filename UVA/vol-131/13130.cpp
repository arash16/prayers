/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 13130
  Name: Cacho
  Problem: https://onlinejudge.org/external/131/13130.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int v[5];
bool check() {
    for (int i=1; i<5; ++i)
        if (v[i] != v[i-1]+1)
            return 0;
    return 1;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", v,v+1,v+2,v+3,v+4);
        sort(v, v+5);
        puts(check() ? "Y" : "N");
    }
}
