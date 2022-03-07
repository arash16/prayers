/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11388
  Name: GCD LCM
  Problem: https://onlinejudge.org/external/113/11388.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, g, l;
    cin>>T;
    while(T--) {
        cin>>g>>l;
        if (l%g) cout << "-1\n";
        else cout << g << " " << l << endl;
    }
}
