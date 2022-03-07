/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 681
  Name: Convex Hull Finding
  Problem: https://onlinejudge.org/external/6/681.pdf
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

int hull(Point P[], int n, int S[]) {
    sort(P, P+n);

    int sz = 0;
    for (int i=0; i<n; ++i) {
        S[sz++] = i;
        while (sz>2 && angle(P[S[sz-3]], P[S[sz-2]], P[S[sz-1]]) <= 0) {
            S[sz-2] = S[sz-1];
            --sz;
        }
    }

    bool sel[616] = {};
    for (int i=1; i<sz; ++i)
        sel[S[i]] = 1;

    for (int i=n-2, t=sz+1; i>=0; --i) if (!sel[i]) {
        S[sz++] = i;
        while (sz>t && angle(P[S[sz-3]], P[S[sz-2]], P[S[sz-1]]) <= 0) {
            S[sz-2] = S[sz-1];
            --sz;
        }
    }

    return sz;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, tmp;
    cin >> T;
    cout << T << '\n';

    Point P[616];
    while (T--) {
        cin >> n;
        for (int i=0; i<n; ++i)
            cin >> P[i];

        int S[616];
        int sz = hull(P, n, S);

        cout << sz << '\n';
        for (int i=0; i<sz; ++i)
            cout << P[S[i]] << '\n';

        if (cin >> tmp)
            cout << "-1\n";
    }
}
