#include <bits/stdc++.h>
using namespace std;


char wd[7][20] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
int dc[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, m, d;
    cin >> T;
    while (T--) {
        cin >> m >> d;
        for (int i=0; i<m-1; ++i)
            d += dc[i];

        cout << wd[(d + 4) % 7] << endl;
    }
}
