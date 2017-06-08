#include <bits/stdc++.h>
using namespace std;


int adj[17], n;
bool chosed[17];
string names[17];
void dfs(int idx, int cnt, int bs) {
    if (n-idx < cnt) return;
    if (!cnt) {
        bool frst = 1;
        for (int i=0; i<n; ++i)
            if (chosed[i]) {
                if (frst) frst = 0;
                else cout << ' ';
                cout << names[i];
            }
        cout << '\n';
        return;
    }

    if (!(bs & (1<<idx))) {
        chosed[idx] = 1;
        dfs(idx+1, cnt-1, bs | adj[idx]);
    }
    chosed[idx] = 0;
    dfs(idx+1, cnt, bs);
}


bool comp(const string &s1, const string &s2) {
    return s1.length() == s2.length() ? s1 < s2 :
           s1.length()  > s2.length();
}

void toupper(string &s) {
    for (int j=s.length()-1; j>=0; --j)
        s[j] = toupper(s[j]);
}

char BUF[1000000];
int main() {
    cout.rdbuf()->pubsetbuf(BUF, 1000000);
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, c, p;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n >> p >> c;
        for (int i=0; i<n; ++i) {
            cin >> names[i];
            toupper(names[i]);
            adj[i] = 1<<i;
        }
        sort(names, names+n, comp);

        map<string, int> ids;
        for (int i=0; i<n; ++i)
            ids[names[i]] = i;

        for (int i=0; i<p; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            toupper(s1); toupper(s2);
            int u = ids[s1],
                v = ids[s2];

            adj[u] |= 1<<v;
            adj[v] |= 1<<u;
        }

        cout << "Set " << cse << ":\n";
        dfs(0, c, 0);
        cout << '\n';
    }
}
