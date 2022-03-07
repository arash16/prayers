/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 587
  Name: There's treasure everywhere!
  Problem: https://onlinejudge.org/external/5/587.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

const double sq2 = sqrt(2);
int di[91],
    dx[] = {0, 1, 0, -1},
    dy[] = {1, 0, -1, 0};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(3);
    di['N']=0; di['E']=1; di['S']=2; di['W']=3;

    string str;
    for (int cse=1; cin >> str && str!="END"; ++cse) {
        double dd = 0, x = 0, y = 0;
        for (int i=0; str[i]; ++i)
            if (str[i]>='0' && str[i]<='9')
                dd = dd*10 + str[i]-'0';
            else {
                bool isd = str[i+1]!='.' && str[i+1]!=',';
                if (isd) dd /= sq2;

                x += dx[di[str[i]]] * dd;
                y += dy[di[str[i]]] * dd;

                if (!isd) dd = 0;
            }

        cout << "Map #" << cse
            << "\nThe treasure is located at (" << x << ',' << y
            << ").\nThe distance to the treasure is " << sqrt(x*x+y*y)
            << ".\n\n";
    }
}
