#include <bits/stdc++.h>
using namespace std;

int w, h;
bool M1[101][101], M2[101][101];
int a1[4000], a2[4000],
    S[101][101];
void makeUids(bool M[101][101], int res[]) {
    for (int i=0; i<h; ++i)
        for (int j=0, c=0; j<w; ++j)
            S[i][j] += M[i][j] ? ++c : c=0;

    for (int j=0; j<w; ++j)
        for (int i=0, c=0; i<h; ++i)
            S[i][j] += M[i][j] ? ++c : c=0;

    for (int i=h-1; i>=0; --i)
        for (int j=w-1, c=0; j>=0; --j)
            S[i][j] += M[i][j] ? ++c : c=0;

    int k = 0;
    for (int j=w-1; j>=0; --j)
        for (int i=h-1, c=0; i>=0; --i)
            if (S[i][j] += M[i][j] ? ++c : c=0) {
                res[k++] = S[i][j];
                S[i][j] = 0;
            }
    sort(res, res+k);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, T; cin >> T;
    while (T--) {
        cin >> w >> h >> n;

        for (int i=0; i<h; ++i) {
            memset(M1[i], 0, w);
            memset(M2[i], 0, w);
        }

        for (int i=0, x, y; i<n; ++i) {
            cin >> x >> y;
            M1[y][x] = 1;
        }
        makeUids(M1, a1);

        for (int i=0, x, y; i<n; ++i) {
            cin >> x >> y;
            M2[y][x] = 1;
        }
        makeUids(M2, a2);

        bool eq = 1;
        for (int i=0; eq && i<n; ++i)
            eq &= a1[i] == a2[i];

        cout << (eq ? "YES\n" : "NO\n");
    }
}
