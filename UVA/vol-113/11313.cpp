/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11313
  Name: Gourmet Games
  Problem: https://onlinejudge.org/external/113/11313.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, n, m, cnt;
    cin>>T;
    while (T--) {
        cin >> n >> m;
        for (cnt=0; n>=m; ) {
            cnt += n/m;
            n = (n/m) + (n%m);
        }
        if (n==1) cout << cnt << endl;
        else puts("cannot do this");
    }
}
