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

std::istream& operator>> (std::istream& stream, Point& p) {
    stream >> p.x >> p.y;
    return stream;
}
std::ostream& operator<< (std::ostream& stream, const Point p) {
    stream << p.x << ' ' << p.y;
    return stream;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(3);

    Point p1, p2, p3, p4;
    while (cin >> p1 >> p2 >> p3 >> p4) {
        if (p1 == p3)
            swap(p1, p2);
        else if (p1 == p4)
            swap(p1, p2),
            swap(p3, p4);
        else if (p2 == p4)
            swap(p3, p4);

        cout << p1 + p4 - p3 << '\n';
    }
}
