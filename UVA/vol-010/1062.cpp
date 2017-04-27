#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    char line[2000];
    for (int cse=1; cin>>line && line[0]!='e'; ++cse) {
        char stks[] = "ZZZZZZZZZZZZZZZZZZZZZZZZZZ";
        int sz = 1;
        for (int i=0; line[i]; ++i) {
            int ind = lower_bound(stks, stks+sz, line[i]) - stks;
            stks[ind] = line[i];
            if (ind >= sz) sz = ind+1;
        }
        printf("Case %d: %d\n", cse, sz);
    }
}
