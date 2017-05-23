#include <bits/stdc++.h>
using namespace std;


char M[16][16];
int C[17][17], Row[16], n;
bool Col[16];
bool check(int i, int j) {
    for (int k=0; k<j; ++k)
        if (abs(i-Row[k]) == abs(j-k))
            return 0;
    return 1;
}

int backtrack(int j) {
    if (j == n) return 1;
    for (int i=0; i<n; ++i)
        if (!Col[i] && !C[i])
            return 0;

    int result = 0;
    for (int i=0; i<n; ++i)
        if (!Col[i] && M[i][j]!='*' && check(i, j)) {
            Row[j] = i;
            Col[i] = 1;
            result += backtrack(j+1);
            Col[i] = 0;
        }
    return result;
}


int main() {
    for (int cse=1; cin >> n && n; ++cse) {
        memset(C, 0, sizeof(C));
        for (int i=0; i<n; ++i) {
            cin >> M[i];
            for (int j=n-1; j>=0; --j)
                C[i][j] = C[i][j+1] + (M[i][j] == '.');
        }

        cout << "Case " << cse << ": " << backtrack(0) << '\n';
    }
}
