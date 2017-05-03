#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(0);

    int pn, bn;
    double X[23], Y[23], V[23], a,b,c,d,e,f,g,  delta, t,x,y;
    while (cin.ignore(10, '=') && cin>>pn) {
        for (int i=0; i<pn; ++i)
            cin >> X[i] >> Y[i] >> V[i];

        cin.ignore(10, '=');
        cin >> bn;
        for (int cse=1; cse<=bn; ++cse) {
            cin >> a >> b >> c >> d >> e >> f >> g;

            cout << "Ball " << cse << " was ";

            if (fabs(a) < 1e-16) t = -c/b;
            else {
                b /= a; c /= a;
                delta = sqrt(b*b - 4*c);
                t = ceil((-b + delta) / 2);
            }
            if (t < 0) t = 0;
            x = d*t + e;
            y = f*t + g;

            if (x<0 || y<0) cout << "foul";
            else {
                bool safe = 1;
                for (int i=0; safe && i<pn; ++i) {
                    double dd = sqrt((X[i]-x)*(X[i]-x) + (Y[i]-y)*(Y[i]-y));
                    if (dd/V[i] < t) safe = 0;
                }
                cout << (safe ? "safe" : "caught");
            }
            cout << " at (" << x << "," << y << ")\n";
        }
    }
}
