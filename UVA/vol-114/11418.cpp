#include <bits/stdc++.h>
using namespace std;


void capitalize(string &s) {
    s[0] = toupper(s[0]);
    for (int i=1; s[i]; ++i)
        s[i] = tolower(s[i]);
}

char R[43];
vector<int> adj[43];
int match[26];
bool seen[26];
bool bpm(int u) {
    for (int v: adj[u])
        if (!seen[v]) {
            seen[v] = 1;
            if (match[v]==-1 || bpm(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    return 0;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    vector<string> names[43];
    for (int cse=1; cse<=T; ++cse) {
        cin >> n;
        for (int i=0, sz; i<n; ++i) {
            cin >> sz;
            adj[i].clear();
            names[i].resize(sz);
            for (int j=0; j<sz; ++j) {
                cin >> names[i][j];
                capitalize(names[i][j]);
                int v = names[i][j][0]-'A';
                if (v < n)
                    adj[i].push_back(v);
            }
        }

        memset(match, -1, sizeof(match));
        for (int i=0; i<n; ++i) {
            memset(seen, 0, 26);
            bpm(i);
        }

        cout << "Case #" << cse << ":\n";
        for (int i=0; i<n; ++i) {
            for (string &s: names[match[i]])
                if (s[0] == 'A'+i) {
                    cout << s << '\n';
                    break;
                }
        }
    }
}
