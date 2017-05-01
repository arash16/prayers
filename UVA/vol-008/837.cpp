#include <bits/stdc++.h>
using namespace std;

struct Event {
    int u, s;
    double t;
    Event(double t, int u, int s):t(t),u(u),s(s){}
    bool operator < (const Event &o) const { return t > o.t; }
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(3);

    int T, n;
    cin >> T;
    double Xl[10000], Xr[10000], C[10000];
    while (T-- && cin >> n) {
        priority_queue<Event> q;
        for (int i=0; i<n; ++i) {
            double x1, x2, t, r;
            cin >> x1 >> t >> x2 >> t >> C[i];
            Xl[i] = min(x1, x2);
            Xr[i] = max(x1, x2);
            q.push(Event(Xl[i], i, 1));
        }

        cout << (n<<1|1) << '\n';
        double cc=1, lx=-1e10000;
        while (!q.empty()) {
            Event e = q.top(); q.pop();
            cout << lx << ' ' << e.t << ' ' << cc << '\n';
            if (e.s) {
                cc *= C[e.u];
                q.push(Event(Xr[e.u], e.u, 0));
            }
            else cc /= C[e.u];
            lx = e.t;
        }
        cout << lx << " +inf 1.000\n";
        if (T) cout << '\n';
    }
}
