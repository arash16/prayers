#include <bits/stdc++.h>
using namespace std;

#define EPS 3e-5

const double nsr=0.58, nlr=1.31;
struct Circle;
struct Rect {
    double x1, y1, x2, y2;
    Rect(){}
    Rect(double x1, double y1, double x2, double y2):x1(x1),y1(y1),x2(x2),y2(y2){}
    bool has(double px, double py) const {
        return px>=x1 && px<=x2 && py>=y1 && py<=y2;
    }
    double area() const { return (x2-x1)*(y2-y1); }
};

struct Circle {
    double x, y, r, r2;
    bool has(double px, double py) const {
        double xx = px-x, yy=py-y;
        return xx*xx+yy*yy <= r2;
    }
} p[300];

bool includes(const Rect &r, const Circle &c) {
    return r.has(c.x, c.y) || r.has(c.x-c.r, c.y) || r.has(c.x+c.r, c.y) || r.has(c.x, c.y-c.r) || r.has(c.x, c.y+c.r);
}

int includes(const Circle &c, const Rect &r) {
    return c.has(r.x1, r.y1) + c.has(r.x2, r.y1) + c.has(r.x1, r.y2) + c.has(r.x2, r.y2);
}

bool intersects(Circle c, Rect r) {
    return includes(r, c) || includes(c, r);
}

int pi[1000000];
double solve(Rect &a, int pi[], int len) {
    double area = a.area();
    if (!len) return area;
    if (area<EPS)
        return area * (4-includes(p[pi[0]], a))/4;

    Rect ar[2] = {a, a};
    if (a.x2-a.x1 > a.y2-a.y1) {
        double mx = (a.x1+a.x2)/2;
        ar[0].x2 = mx;
        ar[0].y2 = a.y2;
        ar[1].x1 = mx;
        ar[1].y1 = a.y1;
    }
    else {
        double my = (a.y1+a.y2)/2;
        ar[0].x2 = a.x2;
        ar[0].y2 = my;
        ar[1].x1 = a.x1;
        ar[1].y1 = my;
    }

    double sum = 0;
    for (int i=0; i<2; ++i) {
        int l2 = 0;
        for (int j=0; j<len; ++j) {
            Circle &c = p[pi[j]];
            int incs = includes(c, ar[i]);
            if (incs == 4) goto cont;

            if (incs || includes(ar[i], c))
                pi[len+(l2++)] = pi[j];
        }
        sum += solve(ar[i], pi+len, l2);
        cont:;
    }
    return sum;
}


int main() {
    int n, m, k1, k2;
    while (cin >> n >> m >> k1 >> k2 && (n||m||k1||k2)) {
        Rect a(0, 0, n, m);

        int k = 0;
        for (int i=0; i<k1; ++i) {
            cin >> p[i].x >> p[i].y;
            p[i].r2 = nsr*nsr;
            p[i].r = nsr;

            if (intersects(p[i], a))
                pi[k++] = i;
        }

        for (int i=0; i<k2; ++i) {
            cin >> p[k1+i].x >> p[k1+i].y;
            p[k1+i].r2 = nlr*nlr;
            p[k1+i].r = nlr;

            if (intersects(p[k1+i], a))
                pi[k++] = k1+i;
        }

        printf("%.2f\n", solve(a, pi, k));
    }
}
