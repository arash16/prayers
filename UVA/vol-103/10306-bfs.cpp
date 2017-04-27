#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y;
    State(int x, int y):x(x),y(y){}
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, n, p, X[43], Y[43], D[313][313];
    cin >> T;
    while (T--) {
        cin >> n >> p;

        for (int i=0; i<n; ++i)
            cin >> X[i] >> Y[i];

        queue<State> q;
        q.push(State(0, 0));
        memset(D, -1, sizeof(D));
        D[0][0] = 0;
        while (!q.empty()) {
            State s = q.front(); q.pop();
            if (s.x*s.x + s.y*s.y == p*p) {
                cout << D[s.x][s.y] << endl;
                goto fin;
            }

            for (int i=0; i<n; ++i) {
                State t(s.x+X[i], s.y+Y[i]);
                if (t.x <= p && t.y <= p)
                if (D[t.x][t.y] == -1) {
                    D[t.x][t.y] = D[s.x][s.y] + 1;
                    q.push(t);
                }
            }
        }
        cout << "not possible\n";
        fin:;
    }
}
