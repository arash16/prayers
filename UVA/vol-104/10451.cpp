#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    double n, s;
    for (int cse=1; cin >> n >> s && n>2; ++cse) {
        double a = PI / n, ca = cos(a);
        double r = sqrt(s / (n*ca*sin(a)));
        double h = r * ca;
        printf("Case %d: %.5f %.5f\n", cse, PI*r*r - s, s - PI*h*h);
    }
}
