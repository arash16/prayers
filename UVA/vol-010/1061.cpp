/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1061
  Name: Consanguine Calculations
  Problem: https://onlinejudge.org/external/10/1061.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


char toStr[8][5] = {
    "O-",
    "A-",
    "B-",
    "AB-",
    "O+",
    "A+",
    "B+",
    "AB+",
};

int P[4][2] = {
    { 0, 0 },
    { 0, 1 },
    { 0, 2 },
    { 1, 2 }
};

int toInt(string s) {
    if (s == "?") return -1;
    int r = 0;
    for (int i=0; s[i]; ++i)
        switch(s[i]) {
            case 'A': r |= 1; break;
            case 'B': r |= 2; break;
            case '+': r |= 4; break;
        }
    return r;
}

void printVec(const vector<int> &vec) {
    if (vec.empty())
        cout << "IMPOSSIBLE";

    else if (vec.size() == 1)
        cout << toStr[vec[0]];

    else {
        cout << '{' << toStr[vec[0]];
        for (int i=1; i<vec.size(); ++i)
            cout << ", " << toStr[vec[i]];
        cout << '}';
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string a, b, c;
    for (int cse=1; cin>>a>>b>>c && a!="E"; ++cse) {
        cout << "Case " << cse << ": ";

        int x = toInt(a),
            y = toInt(b),
            z = toInt(c);

        if (z < 0) {
            cout << a << ' ' << b << ' ';
            vector<int> vec;
            for (int sg=(x|y)>>2; sg>=0; --sg)
                for (int i=0; i<2; ++i)
                    for (int j=0; j<2; ++j) {
                        int u = (sg<<2) | P[x&3][i] | P[y&3][j];
                        if (find(vec.begin(), vec.end(), u) == vec.end())
                            vec.push_back(u);
                    }

            printVec(vec);
            cout << '\n';
        }

        else {
            vector<int> vec;
            int o = (x<0 ? y : x);
            for (int c=0; c<8; ++c)
                if (((c|o)>>2) || !(z>>2))
                    for (int i=0; i<2; ++i)
                        for (int j=0; j<2; ++j) {
                            int u = P[o&3][i] | P[c&3][j];
                            if (u == (z&3) && find(vec.begin(), vec.end(), c) == vec.end())
                                vec.push_back(c);
                        }

            if (y < 0) cout << a << ' ';
            printVec(vec);
            cout << ' ';
            if (x < 0) cout << b << ' ';
            cout << c << '\n';
        }
    }
}
