#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k;
    while (cin >> n >> k && (n||k)) {
        queue<int> q;
        for (int i=1; i<=n; ++i)
            q.push(i);

        int X[43] = {};
        for (int s=0, i=1; !q.empty(); ) {
            if (!s) {
                s = i++;
                if (i > k)
                    i = 1;
            }

            int j = q.front(); q.pop();
            X[j] += s;
            if (X[j] >= 40) {
                s = X[j] - 40;
                printf("%3d", j);
            }
            else {
                q.push(j);
                s = 0;
            }
        }
        cout << endl;
    }
}
