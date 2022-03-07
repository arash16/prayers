/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11878
  Name: Homework Checker
  Problem: https://onlinejudge.org/external/118/11878.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool solve(const string &str) {
    if (str[str.length()-1] == '?')
        return 0;

    int x, y, z;
    if (sscanf(&str[0], "%d+%d=%d", &x, &y, &z)==3)
        return x+y == z;
    else
        if (sscanf(&str[0], "%d-%d=%d", &x, &y, &z)==3)
            return x-y == z;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int cnt = 0;
    string str;
    while (cin >> str)
        if (solve(str))
            ++cnt;
    cout << cnt << endl;
}
