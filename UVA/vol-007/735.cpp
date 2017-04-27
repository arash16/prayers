#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int S[] = {6, 3, 0, 1};
    int nums[55], nn=0;
    bool ff[1000]={}; ff[50] = 1;
    for (int i=0; i<=20; ++i)
        for (int j=1; j<4; ++j)
            ff[i*j] = 1;
    for (int i=0; i<61; ++i)
        if (ff[i])
            nums[nn++] = i;

    int n;
    while (cin >> n && n>0) {
        int c=0, p=0;
        for (int i=0; i<nn; ++i) {
            int x = nums[i];
            for (int j=i; j<nn; ++j) {
                int y = nums[j];
                if (x + y > n) break;
                int z = n-x-y;
                if (z >= y && ff[z]) {
                    ++c;
                    p += S[(x==y)+(y==z)+(z==x)];
                }
            }
        }
        if (!c)
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS.\n";
        else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << c << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << p << ".\n";
        }
        cout << "**********************************************************************\n";
    }
    cout << "END OF OUTPUT\n";
}
