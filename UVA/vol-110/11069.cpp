#include <bits/stdc++.h>
using namespace std;


int main() {
    int DP[77] = { 0, 1, 2, 2 };
    for (int i=4; i<77; ++i)
        DP[i] = DP[i-2] + DP[i-3];

    int n;
    while (cin >> n)
        cout << DP[n] << endl;
}
