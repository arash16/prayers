/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11343
  Name: Isolated Segments
  Problem: https://onlinejudge.org/external/113/11343.pdf
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
    bool operator == (const Point &o) const { return fabs(x-o.x)<EPS && fabs(y-o.y)<EPS; }
    double operator * (const Point o) const { return x*o.x + y*o.y; }
    Point operator - (const Point o) const { return Point(x-o.x, y-o.y); }
    Point operator + (const Point o) const { return Point(x+o.x, y+o.y); }
};

double cross(const Point p1, const Point p2) { return p1.x*p2.y - p1.y*p2.x; }

// leftTurn is positive
double angle(const Point p1, const Point p2, const Point p3) { return cross(p2-p1, p3-p2); }

bool intersect(const Point p1, const Point p2, const Point p3, const Point p4) {
    double a11 = angle(p1, p2, p3), a12 = angle(p1, p2, p4);
    if (a11*a12 > EPS) return 0;

    double a21 = angle(p3, p4, p1), a22 = angle(p3, p4, p2);;
    if (a21*a22 > EPS) return 0;

    if (a11*a12 < -EPS && a21*a22 < -EPS) return 1;
    return (fabs(a11)<EPS && (p1-p3)*(p2-p3) < EPS)
        || (fabs(a12)<EPS && (p1-p4)*(p2-p4) < EPS)
        || (fabs(a21)<EPS && (p3-p1)*(p4-p1) < EPS)
        || (fabs(a22)<EPS && (p3-p2)*(p4-p2) < EPS);
}


std::istream& operator>> (std::istream& stream, Point& p) {
    stream >> p.x >> p.y;
    return stream;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n;
    cin >> T;
    Point Pu[143], Pv[143];
    while (T-- && cin>>n) {
        bool hi[143] = {};
        for (int i=0; i<n; ++i) {
            cin >> Pu[i] >> Pv[i];
            for (int j=0; j<i; ++j)
                if (intersect(Pu[i], Pv[i], Pu[j], Pv[j]))
                    hi[j] = hi[i] = 1;
        }
        int cnt = 0;
        for (int i=0; i<n; ++i)
            if (!hi[i]) ++cnt;
        cout << cnt << '\n';
    }
}
