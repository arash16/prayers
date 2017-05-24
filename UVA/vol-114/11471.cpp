#include <bits/stdc++.h>
using namespace std;

#define TOP 0
#define RIGHT 1
#define BOTTOM 2
#define LEFT 3


string S[12];
int C[12], sz, M[4][3];
int brutecount(int i, int j) {
    if (j == 3) ++i, j=0;
    if (i == 4) return 1;

    int sum = 0;
    for (int k=0; k<sz; ++k)
        if (C[k]>0 && (!i || S[M[i-1][j]][BOTTOM] == S[k][TOP]) && (!j || S[M[i][j-1]][RIGHT] == S[k][LEFT])) {
            M[i][j] = k;
            sum += (C[k]--) * brutecount(i, j+1);
            ++C[k];
        }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        for (int i=0; i<12; ++i)
            cin >> S[i];
        sort(S, S+12);

        C[0] = 1; sz = 1;
        for (int i=1; i<12; ++i)
            if (S[i] == S[sz-1])
                C[sz-1]++;
            else {
                S[sz] = S[i];
                C[sz++] = 1;
            }

        cout << "Case " << cse << ": " << brutecount(0,0) << '\n';
    }
}
