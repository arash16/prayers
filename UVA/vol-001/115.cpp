#include <bits/stdc++.h>
using namespace std;

int seen[313], par[313], ncnt;
map<string, int> nids;
int nameToId(string name) {
    auto r = nids.emplace(name, ncnt);
    if (r.second) ++ncnt;
    return r.first->second;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    memset(par, -1, sizeof(par));

    string s1, s2;
    while (cin >> s1 >> s2 && s1!="no.child")
        par[nameToId(s1)] = nameToId(s2);


    while (cin >> s1 >> s2) {
        int u = nameToId(s1),
            v = nameToId(s2);

        memset(seen, 0, sizeof(seen));
        for (int k=u, d=1; k!=-1; k=par[k], ++d)
            seen[k] = d;

        int r=-1, d1, d2;
        for (int k=v, d=1; k!=-1; k=par[k], ++d)
            if (seen[k]) {
                d1 = seen[k]-2;
                d2 = d-2;
                r = k;
                break;
            }

        int mn = min(d1, d2),
            df = abs(d1 -d2);

        if (r < 0) cout << "no relation\n";
        else if (!d1 && !d2) cout << "sibling\n";
        else if (u == r || v == r) {
            for (int i=2; i<df; ++i)
                cout << "great ";
            if (df > 1) cout << "grand ";
            cout << (u==r ? "parent\n" : "child\n");
        }
        else {
            cout << mn << " cousin";
            if (df) cout << " removed " << df;
            cout << '\n';
        }
    }
}
