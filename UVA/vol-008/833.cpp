#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

struct Point {
    double x, y;
    Point():x(0),y(0){}
    Point(double x, double y):x(x),y(y){}
    bool operator < (const Point &o) const { return x < o.x; }
    bool operator == (const Point &o) const { return fabs(x-o.x)<EPS && fabs(y-o.y)<EPS; }
    double operator * (const Point o) const { return x*o.x + y*o.y; }
    Point operator - (const Point o) const { return Point(x-o.x, y-o.y); }
    Point operator + (const Point o) const { return Point(x+o.x, y+o.y); }
};

struct Line {
    double a, b, c;
    Line():a(0),b(0),c(1){}
    Line(double x, double y):a(x),b(y),c(1){}
    Line(double a, double b, double c):a(a),b(b),c(c){}
    Line(const Point p1, const Point p2) {
        if (fabs(p1.x - p2.x) < EPS) {
            b = 0;
            if (fabs(p1.x) < EPS) a=1, c=0;
            else a = -1/p1.x, c = 1;
        }
        else {
            a = p2.y - p1.y;
            b = p1.x - p2.x;
            c = -p1.y*b - p1.x*a;
        }
    }
    double y(double x0) { return (-a*x0 - c) / b; }
    double x(double y0) { return (-b*y0 - c) / a; }
};

std::istream& operator>> (std::istream& stream, Point& p) {
    stream >> p.x >> p.y;
    return stream;
}

// ------------------------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(0);

    int T, n, m;
    cin >> T;
    Line L[1143];
    Point Pu[1143], Pv[1143], p;
    while (T-- && cin >> n) {
        for (int i=0; i<n; ++i) {
            cin >> Pu[i] >> Pv[i];
            if (Pu[i].x > Pv[i].x)
                swap(Pu[i], Pv[i]);
            L[i] = Line(Pu[i], Pv[i]);
        }
        cin >> m;
        while (m--) {
            cin >> p;
            int bi = 0;
            while (bi >= 0) {
                bi = -1;
                double by = 0;
                for (int i=0; i<n; ++i)
                    if (p.x > Pu[i].x && p.x < Pv[i].x) {
                        double yy = L[i].y(p.x);
                        if (yy > by && yy < p.y)
                            bi = i,
                            by = yy;
                    }
                if (bi != -1)
                    p = Pu[bi].y < Pv[bi].y ? Pu[bi] : Pv[bi];
            }
            cout << p.x << '\n';
        }
        if (T) cout << '\n';
    }
}
