#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char str[100];
    int T;
    cin >> T;
    while (T--) {
        cin >> str;

        long long la=0, lb=1, ra=1, rb=0;
        for (int i=0; str[i]; ++i)
            if (str[i] == 'L') {
                ra += la;
                rb += lb;
            }
            else {
                la += ra;
                lb += rb;
            }
        cout << (la+ra) << '/' << (lb+rb) << endl;
    }
}
