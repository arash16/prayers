/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11548
  Name: Blackboard Bonanza
  Problem: https://onlinejudge.org/external/115/11548.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


bool isHopefull(const string &s1, const string &s2, int best) {
    if (s1.length()<=best || s2.length()<=best)
        return 0;

    char cnt[26] = {};
    for (int i=0; i<s1.length(); ++i)
        ++cnt[s1[i]-'A'];

    int result = 0;
    for (int i=0; i<s2.length(); ++i)
        if (cnt[s2[i]-'A']) {
            --cnt[s2[i]-'A'];
            if (++result > best)
                return 1;
        }
    return 0;
}

int candies(const string &s1, const string &s2) {
    int result = 0;
    for (int j=0; j<s2.length(); ++j) {
        int cnt = 0;
        for (int i=0; i<s1.length() && j+i<s2.length(); ++i)
            if (s1[i] == s2[j+i])
                ++cnt;

        result = max(result, cnt);
    }
    return result;
}

bool comp(const string &s1, const string &s2) {
    return s1.length() == s2.length() ? s1 < s2
        : s1.length() > s2.length();
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    string S[77];
    while (T-- && cin >> n) {
        for (int i=0; i<n; ++i)
            cin >> S[i];
        sort(S, S+n, comp);

        int best = 0;
        for (int d=1; d<n; ++d)
            for (int i=0; i<n-d; ++i) {
                int j = i+d;
                if (isHopefull(S[i], S[j], best))
                    best = max(best, max(candies(S[i], S[j]), candies(S[j], S[i])));
            }

        cout << best << endl;
    }
}
