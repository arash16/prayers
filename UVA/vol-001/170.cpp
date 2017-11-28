#include <bits/stdc++.h>
using namespace std;


char cards[] = "A23456789TJQK";
int ranks[128];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    for (int i=0; i<13; ++i)
        ranks[cards[i]] = i;

    string X[52];
    while (cin >> X[0] && X[0]!="#") {
        for (int i=1; i<52; ++i)
            cin >> X[i];

        stack<string> st[13];
        for (int i=51; i>=0; --i)
            st[(51-i) % 13].push(X[i]);

        string last;
        int expo = 0, pos = 12;
        while (!st[pos].empty()) {
            last = st[pos].top();
            st[pos].pop();
            pos = ranks[last[0]];
            ++expo;
        }

        printf("%02d,%s\n", expo, last.c_str());
    }
}
