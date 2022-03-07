/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10790
  Name: How Many Points of Intersection?
  Problem: https://onlinejudge.org/external/107/10790.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    long long n, m;
    for (int cse=1; cin>>n>>m && (n||m); ++cse)
        cout << "Case " << cse << ": " << (n*(n-1)/2*m*(m-1)/2) << endl;
}
