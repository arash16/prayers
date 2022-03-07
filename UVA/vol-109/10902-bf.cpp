/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10902
  Name: Pick-up Sticks
  Problem: https://onlinejudge.org/external/109/10902.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


struct Point {
    double x, y;
    Point():x(0),y(0){}
    Point(double x, double y):x(x),y(y){}
    bool operator < (const Point &o) const { return x < o.x; }
    double operator * (const Point o) const { return x*o.x + y*o.y; }
    Point operator - (const Point o) const { return Point(x-o.x, y-o.y); }
    Point operator + (const Point o) const { return Point(x+o.x, y+o.y); }
};

double cross(const Point p1, const Point p2) { return p1.x*p2.y - p1.y*p2.x; }
double angle(const Point p1, const Point p2, const Point p3) { return cross(p2-p1, p3-p2); }
bool intersect(const Point p1, const Point p2, const Point p3, const Point p4) {
    if (angle(p1, p2, p3)*angle(p1, p2, p4) > 0) return 0;
    return angle(p3, p4, p1)*angle(p3, p4, p2) <= 0;
}

std::istream& operator>> (std::istream& stream, Point& p) {
    stream >> p.x >> p.y;
    return stream;
}

// -------------------------------------------------------------------------------


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int R[1143], n;
    Point Pu[100143], Pv[100143];
    while (cin >> n && n) {
        int sz = 0;
        for (int i=0; i<n; ++i) {
            cin >> Pu[i] >> Pv[i];
            int k = 0;
            for (int j=0; j<sz; ++j)
                if (!intersect(Pu[i], Pv[i], Pu[R[j]], Pv[R[j]]))
                    R[k++] = R[j];
            R[k++] = i;
            sz = k;
        }

        cout << "Top sticks: ";
        for (int i=0; i<sz; ++i) {
            cout << R[i]+1;
            if (i<sz-1) cout << ", ";
            else cout << ".";
        }
        cout << '\n';
    }
}
