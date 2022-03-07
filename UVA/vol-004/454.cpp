/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 454
  Name: Anagrams
  Problem: https://onlinejudge.org/external/4/454.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool isempty(const string &str) {
    for (int i=0; str[i]; ++i)
        if (str[i] != ' ')
            return 0;
    return 1;
}

int wc[114][256];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T; cin >> T;
    cin.ignore(100, '\n');
    cin.ignore(100, '\n');
    while (T--) {
        string str;
        vector<string> v;
        while (getline(cin, str) && !isempty(str))
            v.push_back(str);
        sort(v.begin(), v.end());


        memset(wc, 0, sizeof(wc));
        for (int i=0; i<v.size(); ++i)
            for (int j=0; v[i][j]; ++j)
                if (v[i][j] != ' ')
                    wc[i][v[i][j]]++;

        for (int i=0, sz=v.size(); i<sz; ++i)
            for (int j=i+1; j<sz; ++j)
                if (!memcmp(wc[i], wc[j], 256*sizeof(int)))
                    cout << v[i] << " = " << v[j] << endl;
        if (T) cout << endl;
    }
}
