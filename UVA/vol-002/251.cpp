#include <bits/stdc++.h>
using namespace std;


void cleanup(string &s) {
    bool used[26]={};
    int sz = 0;
    for (int i=0; i<s.length(); ++i)
        if (!used[s[i]-'a']) {
            used[s[i]-'a'] = 1;
            s[sz++] = s[i];
        }
    s.resize(sz);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    string S[17][17], D[17][17][17], str;
    for (int cse=1; cin >> n >> m && n; ++cse) {
        if (cse > 1) cout << "\n";
        cout << "NTA " << cse << "\n";

        cin.ignore(100, '\n');
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                getline(cin, S[i][j]);

        string terms = "";
        for (int i=n-m; i<n; ++i)
            terms += 'a' + i;

        while (getline(cin, str) && str!="#") {
            int l = str.length();
            if (l==1) {
                cout << (str[0]-'a'>=n-m ? "accept " : "reject ") << str << "\n";
                continue;
            }
            for (int i=0; i<l; ++i)
                for (int j=0; j<=i; ++j)
                    for (int k=0; k<n; ++k)
                        D[i][j][k] = "";

            for (int j=0; j<l-1; ++j)
                D[l-2][j][str[j]-'a'] = str[j+1];

            for (int i=l-3; i>=0; --i)
                for (int j=0; j<=i; ++j) {
                    for (int k1=0; k1<n; ++k1)
                        for (char c2: D[i+1][j][k1]) {
                            int k2 = c2 - 'a';
                            if (S[k1][k2].length())
                                for (char c3: D[i+1][j+1][k2]) {
                                    int k3 = c3 - 'a';

                                    for (char ci: S[k1][k2])
                                        D[i][j][ci-'a'] += S[k2][k3];
                                }
                        }

                    for (int k=0; k<n; ++k)
                        cleanup(D[i][j][k]);
                }

            for (int k=0; k<n; ++k)
                for (char c: D[0][0][k]) {
                    if (S[k][c-'a'].find_first_of(terms) != string::npos) {
                        cout << "accept ";
                        goto done;
                    }
                }
            cout << "reject ";
            done: cout << str << "\n";
        }
    }
}
