/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11689
  Name: Soda Surpler
  Problem: https://onlinejudge.org/external/116/11689.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, e, f, c;
    cin >> T;
    while(T--) {
        cin >> e >> f >> c;
        e += f;
        f = 0;

        while (e >= c) {
            f += e/c;
            e = e/c + e%c;
        }

        cout << f << endl;
    }
}
