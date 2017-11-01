#include <bits/stdc++.h>
using namespace std;


int solve(int n) {
    if (n == 1) return 1;

    int sq = sqrt(n), sum = 0;
    for (int i=2; i<=sq; ++i)
        if (n % i == 0) {
            int x = 1;
            while (n % i == 0)
                x *= i,
                n /= i;
            sum += x;
            sq = sqrt(n);
        }
    return n>1 ? sum + n : sum;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    for (int cse=1; cin >> n && n; ++cse) {
        unsigned int sum = solve(n);
        if (sum == n) ++sum;
        cout << "Case " << cse << ": " << sum << endl;
    }
}
