#include <bits/stdc++.h>
using namespace std;

bool F[61];
double D[7];
int G[7], Y[7], R[7], S[7], n;
bool check(int s) {
    if (s > 60) return 0;
    for (int i=0; i<n; ++i) {
        double tm = fmod(60 * 60 * D[i] / s, S[i]);
        if (tm > G[i] + Y[i])
            return 0;
    }
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    for (int cse=1; cin >> n && n>-1; ++cse) {
        for (int i=0; i<n; ++i) {
            cin >> D[i] >> G[i] >> Y[i] >> R[i];
            S[i] = G[i] + Y[i] + R[i];
        }

        cout << "Case " << cse << ": ";
        int l = 0;
        bool some = 0;
        for (int s=30; s<=61; ++s) {
            bool fs = check(s);
            if (fs) {
                if (!l) l = s;
            }
            else if (l) {
                if (!some) some = 1;
                else cout << ", ";

                cout << l;
                if (l < s-1)
                    cout << '-' << s-1;
                l = 0;
            }
        }
        if (!some)
            cout << "No acceptable speeds.";
        cout << "\n";
    }
}
