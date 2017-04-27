#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    bool fl[55];
    string cards[55], cd, word;
    while (cin >> n && n) {
        int cur = -1;
        memset(fl, 0, n);
        for (int i=0; i<n; ++i) {
            cin >> cd >> word;
            for (int j=word.length(); j>0; --j)
                for (cur = (cur + 1) % n; fl[cur]; cur = (cur + 1) % n);
            cards[cur] = cd;
            fl[cur] = 1;
        }
        cout << cards[0];
        for (int i=1; i<n; ++i)
            cout << ' ' << cards[i];
        cout << endl;
    }
}
