#include <bits/stdc++.h>
using namespace std;


int n;
double D[61], P[61], cap, mpg, best;
void bt(int idx, double cost, double gas) {
    if (cost >= best) return;
    if (idx == n) { best = cost; return; }

    double geed = (D[idx+1]-D[idx])/mpg;
    if (geed <= gas)
        bt(idx+1, cost, gas - geed);

    if (geed > gas || gas <= cap/2)
        bt(idx+1, cost + 200 + round((cap-gas)*P[idx]), cap - geed);
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(2);

    double iprc, dis;
    for (int cse=1; cin >> dis >> cap >> mpg >> iprc >> n; ++cse) {
        D[n] = dis;
        for (int i=0; i<n; ++i)
            cin >> D[i] >> P[i];

        best = 1e100;
        bt(0, iprc*100, cap-D[0]/mpg);
        cout << "Data Set #" << cse
             << "\nminimum cost = $" << best/100 << '\n';
    }
}
