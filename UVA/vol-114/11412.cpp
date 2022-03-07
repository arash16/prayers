/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11412
  Name: Dig the Holes
  Problem: https://onlinejudge.org/external/114/11412.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


vector<string> perms;
char colors[] = "RGBYOV", ss[5];
bool used[6]; int Ci[128];
void initAll(int idx) {
    if (idx == 4) {
        perms.push_back(ss);
        return;
    }

    for (int i=0; i<6; ++i)
        if (!used[i]) {
            used[i] = 1;
            ss[idx] = colors[i];
            initAll(idx + 1);
            used[i] = 0;
        }
}

bool check(const string &so, const string &sg, int x, int y) {
    int cc[6]={};
    for (int i=0; i<4; ++i)
        if (sg[i] == so[i])
            --x;
        else ++cc[Ci[so[i]]];
    if (x) return 0;

    for (int i=0; i<4; ++i)
        if (sg[i] != so[i])
            if (cc[Ci[sg[i]]]) {
                --cc[Ci[sg[i]]];
                --y;
            }
    return !y;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=0; i<6; ++i)
        Ci[colors[i]] = i;
    initAll(0);

    int T, x1, x2, y1, y2;
    cin >> T;
    string s1, s2;
    while (T--) {
        cin >> s1 >> x1 >> y1
            >> s2 >> x2 >> y2;

        bool flag = false;
        for (string s: perms)
            if (check(s, s1, x1, y1) && check(s, s2, x2, y2)) {
                flag = true;
                break;
            }
        cout << (flag ? "Possible\n" : "Cheat\n");
    }
}
