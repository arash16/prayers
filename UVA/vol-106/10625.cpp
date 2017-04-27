#include <bits/stdc++.h>
using namespace std;

struct CharCount {
    char ch;
    int cnt;
    CharCount(char ch, int cnt):ch(ch),cnt(cnt){}
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char ch;
    string str;
    int T, n, r;
    cin >> T;
    while (T-- && cin>>n) {
        vector<CharCount> rules[127];
        for (int i=0; i<n; ++i) {
            cin >> str;
            int C[127] = {};
            for (int j=3; str[j]; ++j)
                ++C[str[j]];

            vector<CharCount> &v = rules[str[0]];
            for (int i=0; i<127; ++i) if (C[i])
                v.push_back(CharCount(i, C[i]));
        }

        cin >> n;
        while (n--) {
            unsigned long long C[127] = {}, CT[127] = {};
            cin >> str >> ch >> r;
            for (int i=0; str[i]; ++i)
                ++C[str[i]];

            while (r--) {
                for (char ch=33; ch<127; ++ch) {
                    if (rules[ch].size())
                        for (const CharCount &cc: rules[ch])
                            CT[cc.ch] += C[ch]*cc.cnt;
                    else CT[ch] += C[ch];
                    C[ch] = 0;
                }

                swap(CT, C);
            }
            cout << C[ch] << "\n";
        }
    }
}
