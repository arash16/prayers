/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1727
  Name: Counting Weekend Days
  Problem: https://onlinejudge.org/external/17/1727.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char daysn[7][4] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
char montn[12][4]= {
    "JAN", "FEB", "MAR", "APR", "MAT", "JUN",
    "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    map<string, int> did, mid;
    for (int i=0; i<7; ++i)
        did[daysn[i]] = i;

    for (int i=0; i<12; ++i)
        mid[montn[i]] = i;

    int T;
    cin >> T;
    string m, d;
    while (T-- && cin>>m>>d) {
        int mn = mid[m], dn = did[d], c=0;
        for (int i=0; i<days[mn]; ++i)
            if ((dn+i) % 7 >= 5)
                ++c;
        cout << c << '\n';
    }
}
