/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 701
  Name: The Archeologists' Dilemma
  Problem: https://onlinejudge.org/external/7/701.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    double c = log2(10), lg2n, lg2n1, left, right;

    int n;
    while (cin >> n) {
        lg2n = log2(n);
        lg2n1= log2(n+1);

        for (int len = log10(n)+2; ; ++len) {
            left = lg2n + len * c;
            right= lg2n1+ len * c;
            if (int(left) < int(right)) {
                cout << (int)ceil(left) << endl;
                break;
            }
        }
    }
}
