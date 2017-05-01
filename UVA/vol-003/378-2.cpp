#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-8

struct Loint {
    double a, b, c;
    double x() const { return a/c; }
    double y() const { return b/c; }
    Loint():a(0),b(0),c(1){}
    Loint(double x, double y):a(x),b(y),c(1){}
    Loint(double a, double b, double c):a(a),b(b),c(c){}
    Loint(const Loint l1, const Loint l2) {
        double x1 = l1.x(), x2 = l2.x();
        if (fabs(x1 - x2) < EPS) {
            b = 0;
            if (fabs(x1) < EPS) a=1, c=0;
            else a = -1/x1, c = 1;
        }
        else {
            double y1 = l1.y(), y2 = l2.y();
            a = y2 - y1;
            b = x1 - x2;
            c = -y1*b - x1*a;
        }
    }
    void normalize() {
        if (fabs(c-1)>0) {
            a /= c;
            b /= c;
            c = 1;
        }
    }
};

int intersect(const Loint l1, const Loint l2, Loint &r) {
    r.a = l1.b*l2.c - l2.b*l1.c;
    r.b = l2.a*l1.c - l1.a*l2.c;
    r.c = l1.a*l2.b - l2.a*l1.b;
    if (fabs(r.c) < EPS)
        return fabs(r.b)<EPS && fabs(r.a)<EPS ? 2 : 0;
    r.normalize();
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(2);

    cout << "INTERSECTING LINES OUTPUT\n";
    int T; cin >> T;
    Loint p1, p2, p3, p4, p;
    while (T--) {
        cin >> p1.a >> p1.b >> p2.a >> p2.b >> p3.a >> p3.b >> p4.a >> p4.b;
        Loint l1(p1, p2), l2(p3, p4);
        int r = intersect(l1, l2, p);
        if (!r) cout << "NONE\n";
        else if (r>1) cout << "LINE\n";
        else cout << "POINT " << p.a << ' ' << p.b << '\n';
    }
    cout << "END OF OUTPUT\n";
}
