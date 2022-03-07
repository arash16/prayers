/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11489
  Name: Integer Game
  Problem: https://onlinejudge.org/external/114/11489.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool SWins(char str[]) {
    if (!str[1]) return 1;

    int sum=0, cnt=0;
    for (int i=0; str[i]; ++i) {
        int d = str[i] - '0';
        if (d%3 == 0) ++cnt;
        sum += d;
    }

    int r = 9 + sum%3;
    if (r%3 != 0) {
        bool found = 0;
        for (int i=0; !found && str[i]; ++i)
            if ( (r-(str[i]-'0')) % 3 == 0)
                found = 1;
        if (found) ++cnt;
        else return 0;
    }

    return cnt&1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    char str[1024];
    for (int cse=1; T-- && cin >> str; ++cse) {


        cout << "Case " << cse << ": " << (SWins(str) ? "S\n" : "T\n");
    }
}
