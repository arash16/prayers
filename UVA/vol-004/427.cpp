#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-6
long double x, y, w1, w2;
long double f(double t) {
    return w1*cos(t) + w2*sin(t) - y*sin(t)*cos(t);
}

const double pi = acos(-1);
long double maxx() {
    double l = 0, r = pi/2,
        m1, m2;

    while (r-l > EPS) {
        m1 = (l+r)/2;
        m2 = (m1 + r)/2;

        if (f(m1) < f(m2))
             r = m1;
        else l = m1;
    }
    return f(m1);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    string line;
    while (getline(cin, line)) if (line.length()>2) {
        stringstream sin(line);
        sin >> x;
        sin.ignore(100,',');
        sin >> y;

        if (y < x) swap(x, y);
        while (sin >> w1) {
            sin.ignore(100,',');
            sin >> w2;
            if (w2 < w1) swap(w1, w2);
            cout << (x<=maxx() ? 'Y' : 'N');
        }
        cout << endl;
    }
}

