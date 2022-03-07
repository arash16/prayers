/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11340
  Name: Newspaper
  Problem: https://onlinejudge.org/external/113/11340.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

void flush() {
    while(getchar()!='\n');
}

int main(){
    unsigned char ch;
    int T, n, val;
    int costs[256];
    cin>>T;
    while(T--) {
        scanf("%d", &n); flush();
        memset(costs, 0, sizeof(costs));
        for (int i=0; i<n; i++) {
            ch = getchar();
            cin >> val; flush();
            costs[ch] = val;
        }

        cin>>n; flush();
        long long int result = 0;
        while (n>0) {
            ch = getchar();
            result += costs[ch];
            if (ch == '\n') n--;
        }

        printf("%.2f$\n", result/100.0);
    }
}
