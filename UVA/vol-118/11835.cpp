#include <bits/stdc++.h>
using namespace std;

int X[143][143], ord[143][143], scores[143], a;
bool comp(int i, int j) { return X[a][i] < X[a][j]; }

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m, s;
    while (cin >> n >> m && (n||m)) {
        for (a=0; a<n; ++a) {
            for (int j=0; j<m; ++j) {
                cin >> X[a][j];
                ord[a][j] = j;
            }
            sort(ord[a], ord[a]+m, comp);
        }

        cin >> s;
        for (int i=0, c; i<s; ++i) {
            memset(scores, 0, m*sizeof(int));
            cin >> c;
            for (int j=0, score; j<c; ++j) {
                cin >> score;
                for (int k=0; k<n; ++k)
                    scores[ord[k][j]] += score;
            }

            int mx=0;
            for (int j=0; j<m; ++j)
                mx = max(mx, scores[j]);

            bool frst=1;
            for (int j=0; j<m; ++j)
                if (scores[j] == mx) {
                    if (frst) frst=0;
                    else cout << ' ';
                    cout << j+1;
                }
            cout << endl;
        }
    }
}
