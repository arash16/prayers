#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;


int C[36];
int cost(int n, int b) {
    if (!n) return C[0];

    int r = 0;
    while (n)
        r += C[n % b],
        n /= b;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, x;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        if (cse > 1) cout << endl;
        cout << "Case " << cse << ":\n";
        for (int i=0; i<36; ++i)
            cin >> C[i];

        cin >> n;
        while (n--) {
            cin >> x;
            vector<int> r;
            int cc = INF;
            for (int i=2; i<=36; ++i) {
                int c = cost(x, i);
                if (c == cc) r.push_back(i);
                else if (c < cc) {
                    cc = c;
                    r.clear();
                    r.push_back(i);
                }
            }

            cout << "Cheapest base(s) for number " << x << ':';
            for (int b: r)
                cout << ' ' << b;
            cout << endl;
        }
    }
}
