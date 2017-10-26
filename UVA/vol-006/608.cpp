#include <bits/stdc++.h>
using namespace std;


int E[4];
string L[4], R[4];
bool Lb[4][26], Rb[4][26];
bool check(char ch, bool l) {
    int up = l ? 1 : -1, down = -up;
    for (int i=0; i<3; ++i) {
        bool i1 = Lb[i][ch-'A'], i2 = Rb[i][ch-'A'];
        if (E[i]==0 && (i1 || i2)) return 0;
    if (E[i]==up && (i1 || !i2)) return 0;
    if (E[i]==down && (!i1 || i2)) return 0;
    }
    return 1;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        memset(Lb, 0, sizeof(Lb));
    memset(Rb, 0, sizeof(Rb));
        for (int i=0; i<3; ++i) {
        string ee;
        cin >> L[i] >> R[i] >> ee;
        E[i] = ee=="even" ? 0 : ee=="up" ? 1 : -1;
        for (int j=0; L[i][j]; ++j)
            Lb[i][L[i][j]-'A'] = 1,
        Rb[i][R[i][j]-'A'] = 1;
        }

    for (char ch='A'; ch<='L'; ++ch)
        if (check(ch, true))
            cout << ch << " is the counterfeit coin and it is light.\n";
        else if (check(ch, false))
            cout << ch << " is the counterfeit coin and it is heavy.\n";
    }
}
