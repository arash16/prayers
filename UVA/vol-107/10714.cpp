#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, l, n, x;
    cin>>T;
    while (T--) {
        cin>>l>>n;
        int mn=0, mx=0;
        for (int i=0; i<n; i++) {
            cin>>x;
            mn = max(mn, min(x, l-x));
            mx = max(mx, max(x, l-x));
        }

        printf("%d %d\n", mn, mx);
    }
}
