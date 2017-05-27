#include <bits/stdc++.h>
using namespace std;


struct Vol {
    int p1[3], p2[3];
    int volume() const {
        int r = 1;
        for (int i=0; i<3; ++i)
            r *= p2[i]-p1[i];
        return r;
    }

    bool operator == (const Vol &o) const {
        for (int i=0; i<3; ++i)
            if (p1[i]!=o.p1[i] || p2[i]!=o.p2[i])
                return 0;
        return 1;
    }
}
vt[17], V[114];

bool intersect(const Vol &v1, const Vol &v2, Vol &vr) {
    for (int i=0; i<3; ++i) {
        vr.p1[i] = max(v1.p1[i], v2.p1[i]);
        vr.p2[i] = min(v1.p2[i], v2.p2[i]);
        if (vr.p1[i] >= vr.p2[i])
            return 0;
    }
    return 1;
}


int sz;
int dfs(int si, int cnt, const Vol& v) {
    Vol vi;
    int result = (cnt&1 ? 1 : -1) * v.volume();
    for (int i=si; i<sz; ++i)
        if (intersect(v, V[i], vi))
            result += dfs(i+1, cnt+1, vi);
    return result;
}



int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    while (cin >> n) {
        sz = 0;
        for (int i=0; i<n; ++i) {
            cin >> vt[i].p1[0] >> vt[i].p1[1] >> vt[i].p1[2]
                >> vt[i].p2[0] >> vt[i].p2[1] >> vt[i].p2[2];

            for (int j=0; j<i; ++j)
                if (intersect(vt[i], vt[j], V[sz])) {
                    for (int k=0; k<sz; ++k)
                        if (V[k] == V[sz]) {
                            --sz;
                            break;
                        }
                    ++sz;
                }
        }

        int result = 0;
        for (int i=0; i<sz; ++i)
            result += dfs(i+1, 1, V[i]);

        cout << result << '\n';
    }
}
