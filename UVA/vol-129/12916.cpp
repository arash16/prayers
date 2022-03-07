/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 12916
  Name: Perfect Cyclic String
  Problem: https://onlinejudge.org/external/129/12916.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    string str;
    while (T-- && cin >> str) {
        int l = 1;
        for (int i=1; str[i]; ++i)
            if (str[i] != str[i%l])
                l = i+1;
        if (str.length()%l)
            l = str.length();
        cout << l << '\n';
    }
}
