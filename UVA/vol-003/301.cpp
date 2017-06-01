#include <bits/stdc++.h>
using namespace std;


struct Order {
    int st, ed, cn;
    int price() const { return (ed-st)*cn; }
    bool operator < (const Order &o) const {
        return st!=o.st ? st < o.st : price() > o.price();
    }
}
O[23];

int L[17], H[23], best, n, m, p;
void bt(int idx, int sum, int cap, int lst=-1) {
    if (sum + H[idx] <= best) return;
    if (idx == m) {
        best = sum;
        return;
    }

    int st = O[idx].st;
    for (int i=st; i>lst; --i)
        cap += L[i];

    if (O[idx].cn <= cap) {
        L[O[idx].ed] += O[idx].cn;
        bt(idx+1, sum + O[idx].price(), cap - O[idx].cn, st);
        L[O[idx].ed] -= O[idx].cn;
    }
    bt(idx+1, sum, cap, st);
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin >> n >> p >> m && (n||p||m)) {
        for (int i=0; i<m; ++i)
            cin >> O[i].st >> O[i].ed >> O[i].cn;
        sort (O, O+m);

        H[m] = 0;
        for (int i=m-1; i>=0; --i)
            H[i] = H[i+1] + O[i].price();

        best = 0;
        bt(0, 0, n);
        cout << best << '\n';
    }
}
