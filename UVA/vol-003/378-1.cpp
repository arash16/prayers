#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8
struct Point {
    double x, y;
    Point():x(0),y(0){}
    Point(double x, double y):x(x),y(y){}
};
std::istream& operator>> (std::istream& stream, Point& p) {
    stream >> p.x >> p.y;
    return stream;
}
std::ostream& operator<< (std::ostream& stream, const Point p) {
    stream << p.x << ' ' << p.y;
    return stream;
}


struct Line {
    Point u, v;
    Line(){}
    Line(const Point u, const Point v):u(u),v(v){}
    bool isVertical() const { return fabs(u.x-v.x) < EPS; }
    double slope() const { return (u.y-v.y) / (u.x-v.x); }
    double f(double x) const { return slope() * (x - u.x) + u.y; }
};
std::istream& operator>> (std::istream& stream, Line& l) {
    stream >> l.u >> l.v;
    return stream;
}

double dist2(const Point p1, const Point p2) {
    double xx = p1.x - p2.x, yy = p1.y - p2.y;
    return xx*xx + yy*yy;
}
double dist(const Point p1, const Point p2) { return sqrt(dist(p1, p2)); }
// double dist(const Point p, const Line l) {}

bool intersect(const Line l, const Point p) {
    return l.isVertical() ? p.x == l.u.x
        : fabs(l.f(p.x) - p.y) < EPS;
}

int intersect(const Line l1, const Line l2, Point &r) {
    double
        x12 = l1.u.x - l1.v.x,
        y12 = l1.u.y - l1.v.y,
        x34 = l2.u.x - l2.v.x,
        y34 = l2.u.y - l2.v.y,
        den = x12*y34 - y12*x34;

    if (fabs(den) < EPS)
        return intersect(l1, l2.u) ? 2 : 0;

    double
        de1 = l1.u.x*l1.v.y - l1.u.y*l1.v.x,
        de2 = l2.u.x*l2.v.y - l2.u.y*l2.v.x;

    r.x = (de1*x34 - x12*de2) / den;
    r.y = (de1*y34 - y12*de2) / den;
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(2);

    cout << "INTERSECTING LINES OUTPUT\n";
    int T; cin >> T;
    Line l1, l2;
    Point p;
    while (T--) {
        cin >> l1 >> l2;
        int r = intersect(l1, l2, p);
        if (!r) cout << "NONE\n";
        else if (r>1) cout << "LINE\n";
        else cout << "POINT " << p << '\n';
    }
    cout << "END OF OUTPUT\n";
}
