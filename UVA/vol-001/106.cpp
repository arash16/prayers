#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

#define MAXN 1000001
int rp[MAXN], us[MAXN], uss[MAXN];
void setUsm(int i, int v) {
    if (us[i]==0 || v < us[i])
        us[i] = v;
}

int main(){
    for (int m=2; m<=1000; m++) {
        bool me = m&1;
        int m2 = m*m;
        for (int n=1; n<m; n++)
            if (((n&1)^me) && gcd(m, n)==1) {
                int n2=n*n;
                int a=m2-n2, b=(m*n)<<1, c=m2+n2;
                if (c < MAXN) rp[c]++;
                for (int k=1; k*c < MAXN; k++) {
                    setUsm(k*a, k*c);
                    setUsm(k*b, k*c);
                    setUsm(k*c, k*c);
                }
            }
    }

    for (int i=1; i<MAXN; i++) {
        rp[i] = rp[i-1] + rp[i];
        if (us[i]) uss[us[i]]++;
        uss[i] += uss[i-1];
    }

    int n;
    while (cin>>n)
        printf("%d %d\n", rp[n], n-uss[n]);
}
