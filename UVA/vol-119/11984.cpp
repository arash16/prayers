/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11984
  Name: A Change in Thermal Unit
  Problem: https://onlinejudge.org/external/119/11984.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int cse=1; cse<=T; cse++) {
        int c, d;
        cin >> c >> d;
        printf("Case %d: %.2f\n", cse, c + 5*d/9.0);
    }
}
