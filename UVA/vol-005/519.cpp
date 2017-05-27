#include <bits/stdc++.h>
using namespace std;

#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3


bool match[128][128];
int C[43], n, m, sz;
string P[43];
char M[7][7];
bool backtrack(char l, int x, int y) {
    if (y == n && M[x-1][n]!='F')
        return 0;

    if (x > m) {
        if (l != 'F') return 0;
        x=1; ++y;
    }

    if (y > n) return 1;


    for (int i=0; i<sz; ++i)
        if (C[i] > 0 && match[ l ][ P[i][LEFT] ] && match[ M[x][y-1] ][ P[i][TOP] ]) {
            --C[i];
            M[x][y] = P[i][BOTTOM];
            if (backtrack(P[i][RIGHT], x+1, y))
                return 1;
            ++C[i];
        }

    return 0;
}

bool solve() {
    sort(P, P+n*m);
    sz = C[0] = 1;
    int cnt[4] = {};
    for (int j=0; j<4; ++j)
        cnt[j] += P[0][j]=='F';
    for (int i=1; i<n*m; ++i) {
        for (int j=0; j<4; ++j)
            cnt[j] += P[i][j]=='F';

        if (P[i] != P[sz-1])
            P[sz++] = P[i],
            C[sz-1] = 1;
        else
            C[sz-1]++;
    }

    if (cnt[TOP]!=m || cnt[BOTTOM]!=m || cnt[LEFT]!=n || cnt[RIGHT]!=n)
        return 0;

    return backtrack('F', 1, 1);
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    match['F']['F'] =
    match['O']['I'] =
    match['I']['O'] = 1;

    memset(M, 'F', sizeof(M));
    while (cin>>n>>m && (n||m)) {
        for (int i=0; i<n*m; ++i)
            cin >> P[i];

        cout << (solve() ? "YES\n" : "NO\n");
    }
}
