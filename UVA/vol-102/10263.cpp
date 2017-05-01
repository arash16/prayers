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
        if (c!=1 && fabs(c)>0) {
            a /= c;
            b /= c;
            c = 1;
        }
    }
    double operator * (const Loint o) const { return x()*o.x() + y()*o.y(); }
    Loint operator - (const Loint o) const { return Loint(x()-o.x(), y()-o.y(), 1); }
};

double dist2(const Loint p1, const Loint p2) {
    double xx = p1.x() - p2.x();
    double yy = p1.y() - p2.y();
    return xx*xx + yy*yy;
}
double dist(const Loint p1, const Loint p2) { return sqrt(dist2(p1, p2)); }

int intersect(const Loint l1, const Loint l2, Loint &r) {
    r.a = l1.b*l2.c - l2.b*l1.c;
    r.b = l2.a*l1.c - l1.a*l2.c;
    r.c = l1.a*l2.b - l2.a*l1.b;
    if (fabs(r.c) < EPS)
        return fabs(r.b)<EPS && fabs(r.a)<EPS ? 2 : 0;
    r.normalize();
    return 1;
}

Loint nearest(const Loint l, const Loint p) {
    Loint r;
    intersect(l, Loint(-l.b, l.a, l.b*p.x() - l.a*p.y()), r);
    return r;
}

Loint nearest(const Loint u, const Loint v, const Loint p) {
    if ( (v-u)*(p-u) < EPS ) return u;
    if ( (u-v)*(p-v) < EPS ) return v;
    return nearest(Loint(u, v), p);
}

// -------------------------------------------------------------------------

std::istream& operator>> (std::istream& stream, Loint& p) {
    stream >> p.a >> p.b; p.c = 1;
    return stream;
}
std::ostream& operator<< (std::ostream& stream, const Loint p) {
    stream << p.x() << ' ' << p.y();
    return stream;
}

// -------------------------------------------------------------------------

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(4);

    int n;
    Loint mp, lp, cp, bp;
    while (cin >> mp >> n) {
        double bd = 1e100;
        cin >> lp;
        for (int i=0; i<n; ++i) {
            cin >> cp;

            Loint r = nearest(lp, cp, mp);
            double d = dist2(r, mp);
            if (bd > d) {
                bd = d;
                bp = r;
            }

            lp = cp;
        }

        cout << bp.x() << '\n' << bp.y() << '\n';
    }
}
