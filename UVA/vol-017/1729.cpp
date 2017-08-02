#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    char str[100143];
    for (int cse=1; cse<=T; ++cse) {
        cin >> str;
        int F[26] = {};
        for (int i=0; str[i]; ++i)
            F[str[i]-'a']++;

        int mn = F[0];
        for (int i=1; i<26; ++i)
            mn = min(F[i], mn);

        cout << "Case " << cse << ": " << mn << endl;
    }
}
