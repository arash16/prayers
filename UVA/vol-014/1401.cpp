#include <bits/stdc++.h>
using namespace std;

bool H[400414];
int DP[300313], D[400414][26], n;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string str, s;
    for (int cse=1; cin >> str >> n; ++cse) {
        int scnt = 0;
        memset(D[scnt], 0, 26*sizeof(int));
        for (int i=0; i<n; ++i) {
            cin >> s;
            int st = 0;
            for (int i=0; s[i]; ++i) {
                int u = s[i]-'a';
                if (!D[st][u]) {
                    D[st][u] = ++scnt;
                    memset(D[scnt], 0, 26*sizeof(int));
                    H[scnt] = 0;
                }
                st = D[st][u];
            }
            H[st] = 1;
        }

        DP[str.length()] = 1;
        for (int i=str.length()-1; i>=0; --i) {
            int st = DP[i] = 0;
            for (int j=i; str[j]; ++j) {
                st = D[st][str[j]-'a'];
                if (!st) break;
                if (H[st]) {
                    DP[i] += DP[j+1];
                    if (DP[i] >= 20071027)
                        DP[i] %= 20071027;
                }
            }
        }

        cout << "Case " << cse << ": " << DP[0] << '\n';
    }
}
