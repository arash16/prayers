/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11462
  Name: Age Sort
  Problem: https://onlinejudge.org/external/114/11462.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int cnts[101];
int main(){
    int n;
    while(cin>>n && n) {
        for (int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            cnts[x]++;
        }

        bool first = false;
        for (int i=1; i<101; i++)
            for (;cnts[i]; cnts[i]--) {
                if (first) putchar(' ');
                else first = true;
                cout << i;
            }
        cout << endl;
    }
}
