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

int R[1143], n;
Point Pu[100143], Pv[100143];
bool comp(int i, int j) {
    return Pv[i].x < Pv[j].x;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    set<int, bool(*)(int,int)> top(comp);

    while (cin >> n && n) {
        top.clear();
        for (int i=0; i<n; ++i) {
            cin >> Pu[i] >> Pv[i];
            if (Pu[i].x < Pv[i].x)
                swap(Pu[i], Pv[i]);

            for (auto it = top.lower_bound(i); it != top.end(); )
                if (intersect(Pu[i], Pv[i], Pu[*it], Pv[*it])) {
                    auto it2 = it; ++it;
                    top.erase(it2);
                }
                else ++it;

            swap(Pu[i], Pv[i]);
            top.insert(i);
        }

        vector<int> R(top.begin(), top.end());
        sort(R.begin(), R.end());
        cout << "Top sticks: ";
        for (int i=0; i<R.size(); ++i) {
            if (i) cout << ", ";
            cout << R[i]+1;
        }
        cout << ".\n";
    }
}
