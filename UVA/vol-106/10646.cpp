/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10646
  Name: What is the Card?
  Problem: https://onlinejudge.org/external/106/10646.pdf
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
    for (int cse=1; cse<=T; ++cse) {
        char C[52][3];
        for (int i=0; i<52; ++i)
            cin >> C[i];

        int top = 26, y=0;
        for (int i=0; i<3; ++i) {
            if (top < 0) throw 1;
            int x = isdigit(C[top][0]) ? C[top][0]-'0' : 10;
            y += x;
            top -= 10-x+1;
        }

        cout << "Case " << cse << ": "
             << (y<=top ? C[y] : C[25+y-top]) << endl;
    }
}
