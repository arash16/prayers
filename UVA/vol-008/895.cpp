#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string str;
    vector<string> words;
    while (cin >> str && str!="#")
        if (str.length() <= 7) {
            sort(str.begin(), str.end());
            words.push_back(str);
        }

    cin.ignore(100, '\n');
    while (getline(cin, str) && str[0]!='#') {
        sort(str.begin(), str.end());
        str = str.substr(str.find_first_not_of(" \t"), str.length());

        int cnt = 0;
        for (string &w: words) {
            int i = 0;
            for (char ch: w) {
                while (ch!=str[i] && i<str.length()) ++i;
                if (ch == str[i]) ++i;
                else goto fin;
            }
            ++cnt;
            fin:;
        }
        cout << cnt << endl;
    }
}
