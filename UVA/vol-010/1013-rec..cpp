#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;


int Pr[1001], W[1001];
int memo[32][1001];

int rec(int remW, int i) {
    if (i<0 || remW<=0) return 0;
    if (memo[remW][i] != -1)
        return memo[remW][i];

    int rr = rec(remW, i-1);

    if (remW < W[i])
        return memo[remW][i] = rr;

    return memo[remW][i] = max( rec(remW-W[i], i-1) + Pr[i], rr );
}



int main(){
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for (int i=0; i<n; i++) {
            cin>>Pr[i]>>W[i];
            for (int j=0; j<32; j++)
                memo[j][i] = -1;
        }

        int g, mw, res = 0;
        cin>>g;
        for (int i=0; i<g; i++) {
            cin >> mw;
            res += rec(mw, n-1);
        }

        cout << res << endl;
    }
}
