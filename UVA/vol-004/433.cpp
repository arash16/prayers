#include <bits/stdc++.h>
using namespace std;


int D[] = { 490, 288, 242, 434, 312, 410, 474, 290, 506, 442 },
    B[9], R[9];
int dfs(int idx, int sum, int gr) {
    if (gr > 1) return 0;
    if (idx == 9) {
        if (sum%11 == 0) {
            memcpy(R, B, sizeof(B));
            return 1;
        }
        return 0;
    }

    int r = 0;
    int o = B[idx];
    for (int d=0; d<10; ++d)
        if ((o&D[d]) == o) {
            B[idx] = d;
            r += dfs(idx+1, sum + (9-idx)*d, gr + (o!=D[d]));
            if (r > 1) return 2;
        }
    B[idx] = o;
    return r;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;

    char M[3][43];
    cin.ignore(100, '\n');
    while (T--) {
        for (int i=0; i<3; ++i)
            cin.getline(M[i], 43);

        for (int i=0; i<9; ++i) {
            B[i] = 0;
            for (int y=0; y<3; ++y)
                for (int x=0; x<3; ++x) {
                    char ch = M[y][3*i+x];
                    if (ch=='_' || ch=='|')
                        B[i] |= 1<<(3*y + x);
                }
        }

        int r = dfs(0, 0, 0);
        if (!r) cout << "failure\n";
        else if (r>1) cout << "ambiguous\n";
        else {
            for (int i=0; i<9; ++i)
                cout << R[i];
            cout << '\n';
        }
    }
}
