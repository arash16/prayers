/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11804
  Name: Argentina
  Problem: https://onlinejudge.org/external/118/11804.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


struct Person {
    int a, d;
    string name;
    bool operator < (const Person &o) const { return name < o.name; }
}
P[10];


int bsa, bsd;
bool chosen[10], bchosen[10];
void bt(int idx, int ca, int sa, int sd) {
    if (ca > 5 || idx-ca > 5) return;
    if (idx == 10) {
        if (sa > bsa || (sa == bsa && sd > bsd)) {
            bsa = sa;
            bsd = sd;
            memcpy(bchosen, chosen, sizeof(chosen));
        }
        return;
    }

    chosen[idx] = 1;
    bt(idx+1, ca+1, sa + P[idx].a, sd);
    chosen[idx] = 0;
    bt(idx+1, ca+0, sa, sd + P[idx].d);
}


void printNames(int ids[]) {
    cout << '(' << P[ids[0]].name;
    for (int i=1; i<5; ++i)
        cout << ", " << P[ids[i]].name;
    cout << ")\n";
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cout << "Case " << cse << ":\n";

        for (int i=0; i<10; ++i)
            cin >> P[i].name >> P[i].a >> P[i].d;

        sort(P, P+10);
        bsa = bsd = -1;
        bt(0, 0, 0, 0);

        int att[5], def[5], sum=0;
        for (int i=0, a=0, d=0; i<10; ++i)
            if (bchosen[i])
                att[a++] = i,
                sum += P[i].a;
            else
                def[d++] = i;

        printNames(att);
        printNames(def);
    }
}
