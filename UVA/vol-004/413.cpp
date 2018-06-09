#include <bits/stdc++.h>
using namespace std;



double savg(const vector<int> &v, function<bool(int, int)> cmp) {
    int sum = 0,
        cnt = 0,
        l = 0,
        g = 0;

    for (int i=1; i<v.size(); ++i)
        if (cmp(v[i], v[i-1])) ++l, g = 1;
        else if (v[i] == v[i-1]) l += g || l == i-1;
        else {
            if (g) {
                sum += l;
                cnt++;
            }
            l = g = 0;
        }

    if (g) {
        sum += l;
        cnt++;
    }

    return !cnt ? 0 : double(sum)/cnt;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(6);

    while (1) {
        int x;
        vector<int> v;
        while (cin >> x && x)
            v.push_back(x);
        if (v.empty()) break;

        cout << "Nr values = " << v.size()
             << ":  " << savg(v, greater<int>())
             << ' '   << savg(v, less<int>())
             << endl;
    }
}
