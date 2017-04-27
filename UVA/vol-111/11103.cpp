#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char str[143];
    while (cin >> str && str[0]!='0') {
        vector<char> cons, wffs;
        int nots = 0;
        for (int i=0; str[i]; ++i)
            if (str[i]=='N')
                ++nots;
            else if (str[i]<='Z')
                cons.push_back(str[i]);
            else
                wffs.push_back(str[i]);

        if (wffs.empty()) cout << "no WFF possible\n";
        else {
            string result;
            result += wffs.back();
            wffs.pop_back();
            while (!cons.empty() && !wffs.empty()) {
                result = cons.back() + result + wffs.back();
                cons.pop_back();
                wffs.pop_back();
            }
            while (nots--)
                result = "N" + result;
            cout << result << "\n";
        }
    }
}
