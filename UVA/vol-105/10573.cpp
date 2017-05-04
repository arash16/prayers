#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(4);

    int T, a, b;
    cin >> T;
    char str[100];
    cin.ignore(100, '\n');
    while (T--) {
        cin.getline(str, 100);
        if (sscanf(str, "%d%d", &a, &b)==2)
            cout << PI*((a+b)*(a+b)-a*a-b*b) << '\n';
        else
            cout << PI*a*a/8 << '\n';
    }
}
