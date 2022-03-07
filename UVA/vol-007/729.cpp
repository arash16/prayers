/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 729
  Name: The Hamming Distance Problem
  Problem: https://onlinejudge.org/external/7/729.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int n;
char out[20] = "0000000000000000000";
void print(int i, int d) {
    if (!d) {
        cout<<out<<endl;
        return;
    }
    if (i>=n) return;

    print(i+1, d);
    out[i]='1';
    print(i+1, d-1);
    out[i]='0';
}


int main(){
    int T, h;
    cin>>T;
    while (T--) {
        cin>>n>>h;
        memset(out, '0', sizeof(out));
        out[n]=0;
        print(0, h);
        if (T) cout<<endl;
    }
}
