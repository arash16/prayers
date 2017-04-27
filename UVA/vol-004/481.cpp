#include <stdio.h>
#include <iostream>
using namespace std;

#define MAXN 100000
int n, X[MAXN], M[MAXN], P[MAXN], S[MAXN];
int main(){
    for (n=0; cin>>X[n]; n++);
    int l = 0;
    for (int i=0; i<n; i++) {
        int lo=1, hi=l;
        while (lo<=hi) {
            int mid = (lo+hi+1)>>1;
            if (X[M[mid]] < X[i])
                lo = mid+1;
            else
                hi = mid-1;
        }

        P[i] = M[lo-1];
        M[lo] = i;
        if (lo > l) l = lo;
    }

    printf("%d\n-\n", l);

    int k = M[l];
    for (int i=l-1; i>=0; i--) {
        S[i] = X[k];
        k = P[k];
    }

    for (int i=0; i<l; i++)
        cout << S[i] << endl;
}
