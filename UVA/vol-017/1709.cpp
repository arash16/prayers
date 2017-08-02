#include <bits/stdc++.h>
using namespace std;

unordered_map<int, double> S, C;
double SIN(int x) {
    auto it = S.find(x);
    if (it != S.end())
        return it->second;

    return S[x] = sin(x);
}

double COS(int x) {
    auto it = C.find(x);
    if (it != C.end())
        return it->second;

    return C[x] = cos(x);
}



int n;
double X[1000143], M[1000143], p, a, b, c, d;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(9);

    while (cin >> p >> a >> b >> c >> d >> n) {
        for (int i=1; i<=n; ++i)
            X[i] = p*(sin(a*i + b) + cos(c*i + d));

        M[n] = X[n];
        for (int i=n-1; i>0; --i)
            M[i] = min(X[i], M[i+1]);

        double result = 0;
        for (int i=1; i<n; ++i)
            result = max(result, X[i] - M[i+1]);

        cout << result << endl;
    }
}
