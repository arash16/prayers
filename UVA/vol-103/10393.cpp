#include <bits/stdc++.h>
using namespace std;


char fings[10][10] = {
    "qaz", "wsx", "edc",
    "rfvtgb", "", "", "yhnujm",
    "ik", "ol", "p"
};

bool check(string &s , bool cu[]) {
    for (int i=0; s[i]; ++i)
        if (cu[s[i]])
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m, x;
    while (cin >> n >> m) {
        bool cu[128] = {};
        for (int i=0; i<n; ++i) {
            cin >> x; --x;
            for (int k=0; fings[x][k]; ++k)
                cu[fings[x][k]] = 1;
        }

        string str;
        vector<string> r;
        int mxlen = 0;
        for (int i=0; i<m; ++i) {
            cin >> str;
            if (str.length() < mxlen || !check(str, cu)) continue;

            if (str.length() > mxlen)
                mxlen = str.length(),
                r.clear();

            if (str.length() == mxlen)
                r.push_back(str);
        }

        sort(r.begin(), r.end());
        int sz = !r.empty();
        for (int i=1; i<r.size(); ++i)
            if (r[i] != r[i-1])
                r[sz++] = r[i];

        cout << sz << '\n';
        for (int i=0; i<sz; ++i)
            cout << r[i] << '\n';
    }
}
