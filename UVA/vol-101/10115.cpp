#include <bits/stdc++.h>
using namespace std;


void replace(string &str, const string &oldStr, const string &newStr) {
    int len = oldStr.length(), pos = 0;
    while ((pos = str.find(oldStr, pos)) >= 0)
        str.replace(pos, len, newStr);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while (cin >> n && n) {
        cin.ignore(100, '\n');

        string R1[17], R2[17], str;
        for (int i=0; i<n; ++i)
            getline(cin, R1[i]),
            getline(cin, R2[i]);

        getline(cin, str);
        for (int i=0; i<n; ++i)
            replace(str, R1[i], R2[i]);
        cout << str << endl;
    }
}
