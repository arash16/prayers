#include <bits/stdc++.h>
using namespace std;


bool isprime(int n) {
    for (int i=2, sq=sqrt(n); i<=sq; ++i)
        if (n%i == 0)
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int X[10143] = { 1 };
    for (int i=0; i<10142; ++i)
        X[i+1] = X[i] + (isprime(i*i+i+41) ? 1 : 0);

    int a, b;
    while (cin >> a >> b)
        cout << fixed << setprecision(2)
             << round(10000.0*(X[b+1]-X[a]) / (b-a+1))/100 << endl;
}
