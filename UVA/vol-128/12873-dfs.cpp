#include <bits/stdc++.h>
using namespace std;

int P[501], C[23], match[501], S[501], c, sse;
bool PS[501][23];
vector<int> adjP[501], adjS[23];

bool dfs(int pi) {
    for (int si: adjP[pi])
        if (PS[pi][si] && S[si]!=sse) {
            S[si] = sse;
            if (C[si] < c) {
                ++C[si];
                PS[pi][si] = 0;
                return 1;
            }
            else {
                for (int pi2: adjS[si])
                    if (!PS[pi2][si]) {
                        if (dfs(pi2)) {
                            PS[pi][si] = 0;
                            return 1;
                        }
                    }
            }
        }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, p, s, m;
    cin >> T;
    while (T--) {
        cin >> p >> s >> c >> m;
        memset(match, -1, p*sizeof(int));
        for (int i=0; i<p; ++i) {
            memset(PS[i], 0, s);
            adjP[i].clear();
        }

        memset(C, 0, s*sizeof(int));
        for (int i=0; i<s; ++i)
            adjS[i].clear();

        while (m--) {
            int pi, si;
            cin >> pi >> si;
            adjP[pi-1].push_back(si-1);
            adjS[si-1].push_back(pi-1);
            PS[pi-1][si-1] = 1;
        }

        int result = 0;
        for (int pi=0; pi<p; ++pi) {
            ++sse;
            if (dfs(pi))
                ++result;
        }
        cout << result << "\n";
    }
}
