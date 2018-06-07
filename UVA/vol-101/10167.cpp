#include <bits/stdc++.h>
#define PI 3.141592654
#define EPS 1e-9
#define K 10
using namespace std;


double ang(double y, double x) {
    double t = atan2(y, x);
    return t < 0 ? t+2*PI : t;
}

int n;
double D[143];
int count(double d) {
    int cnt = 0;
    for (int i=0; i<n; ++i)
        if (D[i] >= d && D[i] <= d+PI) {
            if (fabs(D[i]-d) < EPS || fabs(D[i]-(d+PI)) < EPS)
                return 0;
            cnt++;
        }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int x, y, cse=1; cin >> n && n; ++cse) {
        n *= 2;
        for (int i=0; i<n; ++i) {
            cin >> x >> y;
            D[i] = ang(y, x);
        }

        for (int r=1; r<=500; ++r)
            for (int i=0; i<n; ++i) {
                y = round(r * sin(D[i] > PI ? D[i]-PI : D[i]));
                x = round(r * cos(D[i]));
                double d = ang(y, x);
                if ((x||y) && count(d)*2 == n) {
                    cout << -y << ' ' << x << endl;
                    goto fin;
                }
            }

        for (int i=0; i<n; ++i) {
            y = (500-K) * sin(D[i] > PI ? D[i]-PI : D[i]);
            x = (500-K) * cos(D[i]);
            for (int xx=x-K; xx<=x+K; xx++)
                for (int yy=y-K; yy<=y+K; yy++) {
                    double d = ang(yy, xx);
                    if ((xx||yy) && count(d)*2 == n) {
                        int g = __gcd(yy, xx);
                        cout << -yy/g << ' ' << xx/g << endl;
                        goto fin;
                    }
                }
        }

        // Complete BruteForce
        for (int x=-500; x<=500; ++x)
            for (int y=0; y<=500; ++y) if(x||y) {
                double d = ang(y, x);
                if (count(d)*2 == n) {
                    cout << -y << ' ' << x << endl;
                    goto fin;
                }
            }
        fin:;
    }
}
