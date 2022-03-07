/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10916
  Name: Factstone Benchmark
  Problem: https://onlinejudge.org/external/109/10916.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int R[] = { 3, 5, 8, 12, 20, 34, 57, 98, 170, 300, 536, 966, 1754, 3210, 5910, 10944, 20366, 38064, 71421, 134480, 254016 };
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while (cin >> n && n)
        cout << R[n/10 - 196] << endl;
}
