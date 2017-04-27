#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string s1, s2;
    while (getline(cin, s1) && getline(cin, s2)) {
        char c1[26]={}, c2[26]={};
        for (int i=0; s1[i]; ++i) {
            ++c1[s1[i]-'A'];
            ++c2[s2[i]-'A'];
        }
        sort(c1, c1+26);
        sort(c2, c2+26);

        bool p = 1;
        for (int i=0; p && i<26; ++i)
            if (c1[i] != c2[i])
                p = 0;

        cout << (p ? "YES\n" : "NO\n");
    }
}
