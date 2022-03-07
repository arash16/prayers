/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10203
  Name: Snow Clearing
  Problem: https://onlinejudge.org/external/102/10203.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, x1, x2, y1, y2;
    cin >> T;
    while (T--) {
        cin >> x1 >> y1;
        double sum = 0;
        while (cin.ignore(100,'\n') && cin.peek()!='\n')
            if (cin >> x1 >> y1 >> x2 >> y2) {
                int xx = x1 - x2,
                    yy = y1 - y2;
                sum += sqrt(double(xx*xx + yy*yy));
            }

        int mint = round(60.0 * sum / 10000.0),
            hour = mint / 60;
        mint %= 60;

        cout << hour << ':' << setw(2) << setfill('0') << mint << "\n";
        if (T) cout << "\n";
    }
}
