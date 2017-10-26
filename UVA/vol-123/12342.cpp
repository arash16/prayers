#include <bits/stdc++.h>
using namespace std;


int X[] = { 180000, 300000, 400000, 300000 },
    Y[] = { 0, 10, 15, 20, 25 };

int main() {
    long long T, n, t;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> n;

        t = 0;
        for (int i=0; i<4 && n>0; ++i) {
            t += (n > X[i] ? X[i] : n) * Y[i];
            n -= X[i];
        }

        if (n > 0)
            t += n * Y[4];

        if (t > 0) {
            t = ceil(t / 100.0);
            if (t > 0 && t < 2000)
                t = 2000;
        }

        cout << "Case " << cse << ": " << t << endl;
    }
}
