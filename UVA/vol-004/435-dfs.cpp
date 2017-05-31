#include <bits/stdc++.h>
using namespace std;


int X[23], R[23], hs, n;
bool inside[23];
void dfs(int st, int sum) {
    for (int i=0; i<n; ++i)
        if (!inside[i] && sum+X[i] > hs)
            ++R[i];

    for (int i=st; i<n; ++i)
        if (!inside[i] && sum+X[i] <=hs) {
            inside[i] = 1;
            dfs(i+1, sum+X[i]);
            inside[i] = 0;
        }
}


int main() {
    int T;
    cin >> T;
    while (T-- && cin>>n) {
        int sum = 0;
        for (int i=0; i<n; ++i) {
            cin >> X[i];
            sum += X[i];
            R[i] = 0;
        }

        hs = sum>>1;
        dfs(0, 0);
        for (int i=0; i<n; ++i)
            printf("party %d has power index %d\n", i+1, R[i]);
        cout << endl;
    }
}
