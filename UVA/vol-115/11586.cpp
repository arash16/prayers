/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11586
  Name: Train Tracks
  Problem: https://onlinejudge.org/external/115/11586.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    cin.ignore(100, '\n');
    while (T--) {
        string str;
        getline(cin, str);

        int f=0, m=0;
        for (int i=0; str[i]; ++i)
            if (str[i]=='F') ++f;
            else if (str[i]=='M') ++m;

        cout << (f>1 && f==m ? "LOOP\n" : "NO LOOP\n");
    }
}
