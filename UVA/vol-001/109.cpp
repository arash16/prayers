/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 109
  Name: SCUD Busters
  Problem: https://onlinejudge.org/external/1/109.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8
struct Point {
    long long x, y;
    Point():x(0),y(0){}
    Point(long long x, long long y):x(x),y(y){}
    bool operator < (const Point &o) const { return y == o.y ? x < o.x : y < o.y; }
    Point operator - (const Point o) const { return Point(x-o.x, y-o.y); }
    Point operator + (const Point o) const { return Point(x+o.x, y+o.y); }
    long long operator * (const Point o) const { return x*o.x + y*o.y; }
};

std::istream& operator>> (std::istream& stream, Point& p) {
    stream >> p.x >> p.y;
    return stream;
}

std::ostream& operator<< (std::ostream& stream, const Point p) {
    stream << p.x << ' ' << p.y;
    return stream;
}

long long cross(const Point p1, const Point p2) { return p1.x*p2.y - p1.y*p2.x; }

// leftTurn is positive
long long angle(const Point p1, const Point p2, const Point p3) { return cross(p2-p1, p3-p2); }

// -----------------------------------------------------------------------------------------------

vector<Point> convex_hull(vector<Point> P) {
    // Step 1: find lowest left point
    int k = 0;
    for (int i=P.size()-1; i>0; --i)
        if (P[i] < P[k])
            k = i;
    swap(P[k], P[0]);

    // Step 2: sort by polar angle to first point
    sort(++P.begin(), P.end(), [=](const Point &a, const Point &b) {
        return angle(a, P[0], b) < 0;
    });
    P.push_back(P[0]);

    // Step 3: select all points with left turns
    vector<Point> v;
    for (Point p: P) {
        while (v.size()>1 && angle(v[v.size()-2], v.back(), p) <= 0)
            v.pop_back();
        v.push_back(p);
    }

    return v;
}


bool inPoly(const vector<Point> P, const Point &p) {
    for (int i=P.size()-1; i>0; --i)
        if (angle(P[i-1], P[i], p) < 0)
            return 0;
    return 1;
}

// area of convex polygon wehre v[0] == v[n]
double area(vector<Point> v) {
    double sum = 0;
    for (int i=v.size()-1; i>0; --i)
        sum += cross(v[i-1], v[i]);
    return sum / 2;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, sz;
    vector<Point> P[23];
    for (n=0; cin >> sz && sz>=0; ++n) {
        P[n].resize(sz);
        for (int i=0; i<sz; ++i)
            cin >> P[n][i];

        P[n] = convex_hull(P[n]);
    }


    Point p;
    bool bombed[23] = {};
    while (cin >> p) {
        for (int i=0; i<n; ++i)
            if (inPoly(P[i], p))
                bombed[i] = 1;
    }

    double sum = 0;
    for (int i=0; i<n; ++i)
        if (bombed[i])
            sum += area(P[i]);

    cout << fixed << setprecision(2) << sum << endl;
}
