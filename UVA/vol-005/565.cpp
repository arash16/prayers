/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 565
  Name: Pizza Anyone?
  Problem: https://onlinejudge.org/external/5/565.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool chosed[16];
int seen[16][1<<16], cse,
    H[17], adj1[16], adj2[16], maxtc, n;
bool dfs(int idx, int sat) {
    if (sat == (1<<n)-1) return 1;
    if ((sat|H[idx]) != (1<<n)-1) return 0;
    if (idx > maxtc || seen[idx][sat]==cse) return 0;
    seen[idx][sat] = cse;

    chosed[idx] = 0;
    if (dfs(idx+1, sat | adj2[idx])) return 1;

    chosed[idx] = 1;
    return dfs(idx+1, sat | adj1[idx]);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string str;
    for (cse=1; cin >> str; ++cse) {
        for (int i=0; i<16; ++i)
            adj1[i] = adj2[i] = 0;

        maxtc = 0;
        for (n=0; str != "."; ++n) {
            for (int j=1; j<str.length(); j+=2) {
                (str[j-1] == '+' ? adj1 : adj2)[str[j]-'A'] |= 1<<n;
                maxtc = max(maxtc, str[j]-'A');
            }
            cin >> str;
        }

        H[maxtc+1] = 0;
        for (int i=maxtc; i>=0; --i)
            H[i] = H[i+1] | adj1[i] | adj2[i];

        if (!dfs(0, 0))
            cout << "No pizza can satisfy these requests.\n";
        else {
            cout << "Toppings: ";
            int bb=0;
            for (int i=0; i<=maxtc; ++i)
                if (chosed[i])
                    cout << char('A' + i);

            cout << '\n';
        }
    }
}
