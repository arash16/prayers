#include <bits/stdc++.h>
using namespace std;

long long C[17][17];
void inc(long long X[], int n, long long x, int hole) {
    for (int i=0; i<n; ++i)
        if (i<hole-1 || i>hole+1)
            X[i] += x;
}

char nums[] = "123456789ABCDEF", nid[127];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int i=0; nums[i]; ++i)
        nid[nums[i]] = i;

    string s;
    while (cin >> s) {
        int n = s.length();
        for (int i=0; i<n; ++i)
            memset(C[i], 0, n*sizeof(long long)),
            C[0][i] = 1;

        for (int j=0; j<n-1; ++j) {
            if (s[j] != '?') {
                int i = nid[s[j]];
                inc(C[j+1], n, C[j][i], i);
            }
            else for (int i=0; i<n; ++i)
                inc(C[j+1], n, C[j][i], i);
        }

        if (s[n-1]!='?')
            cout << C[n-1][ nid[s[n-1]] ] << "\n";
        else {
            long long sum = 0;
            for (int i=0; i<n; ++i)
                sum += C[n-1][i];
            cout << sum << "\n";
        }
    }
}
