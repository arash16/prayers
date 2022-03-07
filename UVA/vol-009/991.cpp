/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 991
  Name: Safe Salutations
  Problem: https://onlinejudge.org/external/9/991.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int DP[13] = { 1 };
    for (int i=1; i<13; ++i)
        DP[i] = (4*i-2)*DP[i-1]/(i+1);

    int frst = 1, n;
    while (cin >> n) {
        if (frst) frst = 0;
        else cout << endl;
        cout << DP[n] << endl;
    }
}
