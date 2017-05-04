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
    Point operator / (double den) const { return Point(x/den, y/den); }
};

std::istream& operator>> (std::istream& stream, Point& p) {
    stream >> p.x >> p.y;
    return stream;
}

double dist2(const Point p1, const Point p2) {
    double xx = p1.x - p2.x, yy = p1.y - p2.y;
    return xx*xx + yy*yy;
}

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

Line bisector(const Point &a, const Point &b) {
    Line l(a, b);
    Point m = (a+b) / 2;
    swap(l.a, l.b);
    l.b = -l.b;
    l.c = -l.a*m.x - l.b*m.y;
    return l;
}

int intersect(const Line l1, const Line l2, Point &r) {
    r.x = l1.b*l2.c - l2.b*l1.c;
    r.y = l2.a*l1.c - l1.a*l2.c;
    double cc = l1.a*l2.b - l2.a*l1.b;
    if (fabs(cc) < EPS)
        return fabs(r.y)<EPS && fabs(r.x)<EPS ? 2 : 0;
    r.x /= cc;
    r.y /= cc;
    return 1;
}

bool circle3pts(const Point &a, const Point &b, const Point &c, Point &r) {
    return intersect(bisector(a, b), bisector(a, c), r) == 1;
}

// --------------------------------------------------------------------------------------------

double minCoverCircle(Point P[], int n) {
    double cr = 0;
    Point c = P[0];
    for (int i=1; i<n; ++i)
        if (dist2(P[i], c) > cr+EPS) {
            c = P[i]; cr = 0;
            for (int j=0; j<i; ++j)
                if (dist2(P[j], c) > cr+EPS) {
                    c = (P[i] + P[j]) / 2;
                    cr = dist2(P[i], c);
                    for (int k=0; k<j; ++k)
                        if (dist2(P[k], c) > cr+EPS) {
                            circle3pts(P[i], P[j], P[k], c);
                            cr = dist2(P[i], c);
                        }
                }
        }
    return sqrt(cr);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    double r;
    Point P[143];
    while (cin >> n && n) {
        for (int i=0; i<n; ++i)
            cin >> P[i];
        cin >> r;
        cout << (minCoverCircle(P, n) <= r
                    ? "The polygon can be packed in the circle.\n"
                    : "There is no way of packing that polygon.\n"
                );
    }
}
