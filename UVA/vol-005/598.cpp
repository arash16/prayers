#include <bits/stdc++.h>
using namespace std;


int n;
string names[13], line;
bool chosed[13];
void dfs(int idx, int cnt) {
    if (n-idx < cnt) return;
    if (!cnt) {
        bool frst = 1;
        for (int j=0; j<n; ++j)
            if (chosed[j]) {
                if (frst) frst = 0;
                else cout << ", ";
                cout << names[j];
            }
        cout << '\n';
        return;
    }
    if (idx == n) return;

    chosed[idx] = 1;
    dfs(idx+1, cnt-1);
    chosed[idx] = 0;
    dfs(idx+1, cnt);
}

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, l, r;
    cin >> T;
    cin.ignore(100, '\n');
    while (T--) {
        cin.ignore(100, '\n');
        getline(cin, line);
        for (n=0; cin.peek()!='\n' && getline(cin, names[n]); ++n);

        if (line[0]=='*') l=1, r=n;
        else {
            stringstream sin(line);
            sin >> l;
            if (!(sin>>r)) r = l;
        }

        for (int sz=l; sz<=r; ++sz) {
            cout << "Size " << sz << '\n';
            dfs(0, sz);
            cout << '\n';
        }
        if (T) cout << '\n';
    }
}
