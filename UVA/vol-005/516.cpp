/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 516
  Name: Prime Land
  Problem: https://onlinejudge.org/external/5/516.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line;
    while (getline(cin, line) && line!="0") {
        stringstream sin(line);
        int x = 1, p, e;
        while (sin >> p >> e)
            x *= pow(p, e);

        --x;
        vector<int> vec;
        for (int i=2, sq=sqrt(x); i<=sq; ++i)
            if (x % i == 0) {
                int e = 0;
                while (x % i == 0) {
                    x /= i;
                    ++e;
                }

                vec.push_back(e);
                vec.push_back(i);
                sq = sqrt(x);
            }
        if (x > 1) {
            vec.push_back(1);
            vec.push_back(x);
        }

        cout << vec[vec.size()-1];
        for (int i=vec.size()-2; i>=0; --i)
            cout << ' ' << vec[i];
        cout << endl;
    }
}
