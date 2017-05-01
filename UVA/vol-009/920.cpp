#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point():x(0),y(0){}
    Point(double x, double y):x(x),y(y){}
    bool operator < (const Point &o) const { return x < o.x; }
};
std::istream& operator>> (std::istream& stream, Point& p) {
    stream >> p.x >> p.y;
    return stream;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    Point P[143];
    while (T-- && cin >> n) {
        for (int i=0; i<n; ++i)
            cin >> P[i];
        sort(P, P+n);

        double ly = 0, sum = 0;
        for (int i=n-2; i>=0; i-=2)
            if (ly<=P[i].y && ly>=P[i+1].y) {
                double m = (P[i].y-P[i+1].y) / (P[i].x-P[i+1].x);
                double x = (ly - P[i].y)/m + P[i].x;
                double xx = x - P[i].x, yy = ly - P[i].y;
                sum += sqrt(xx*xx + yy*yy);
                ly = P[i].y;
            }

        cout << fixed << setprecision(2) << sum << '\n';
    }
}
