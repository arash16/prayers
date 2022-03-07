/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11264
  Name: Coin Collector
  Problem: https://onlinejudge.org/external/112/11264.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, n, x, y;
    cin>>T;
    while(T--) {
        cin>>n>>x;
        int rs=0, cnt=1;
        for (int i=1; i<n; i++) {
            cin>>y;
            if (rs + x < y) {
                rs += x;
                cnt++;
            }
            x = y;
        }

        cout << cnt << endl;
    }
}
