/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10263
  Name: Railway
  Problem: https://onlinejudge.org/external/102/10263.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

struct Point {
    double x, y;
    Point():x(0),y(0){}
    Point(double x, double y):x(x),y(y){}
    bool operator < (const Point &o) const { return x < o.x; }
    double operator * (const Point o) const { return x*o.x + y*o.y; }
    Point operator - (const Point o) const { return Point(x-o.x, y-o.y); }
};

double dist2(const Point p1, const Point p2) {
    double xx = p1.x - p2.x, yy = p1.y - p2.y;
    return xx*xx + yy*yy;
}
double dist(const Point p1, const Point p2) { return sqrt(dist2(p1, p2)); }

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
};

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

Point nearest(const Line l, const Point p) {
    Point r;
    intersect(l, Line(-l.b, l.a, l.b*p.x - l.a*p.y), r);
    return r;
}

Point nearest(const Point u, const Point v, const Point p) {
    if ( (v-u)*(p-u) < EPS ) return u;
    if ( (u-v)*(p-v) < EPS ) return v;
    return nearest(Line(u, v), p);
}

// -------------------------------------------------------------------------

std::istream& operator>> (std::istream& stream, Point& p) {
    stream >> p.x >> p.y;
    return stream;
}
std::ostream& operator<< (std::ostream& stream, const Point p) {
    stream << p.x << ' ' << p.y;
    return stream;
}

// -------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(4);

    int n;
    Point mp, lp, cp, bp;
    while (cin >> mp >> n) {
        double bd = 1e100;
        cin >> lp;
        for (int i=0; i<n; ++i) {
            cin >> cp;

            Point r = nearest(lp, cp, mp);
            double d = dist2(r, mp);
            if (bd > d) {
                bd = d;
                bp = r;
            }

            lp = cp;
        }

        cout << bp.x << '\n' << bp.y << '\n';
    }
}
