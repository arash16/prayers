#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T, r;
    cin >> T;
    for (int cse=1; cse<=T; ++cse) {
        cin >> r;
        int l = r * 5,
            h = round(l*0.3),
            w1= round(l*0.45),
            w2= l - w1;
        printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n", cse,
                         -w1, h, w2, h, w2,-h,-w1,-h);
    }
}
