#include <stdio.h>
#include <iostream>
using namespace std;

int c[1001], n, m;
bool ispos(int cap) {
    int sum = 0, cnt = 1;
    for (int i=0; i<n; i++)
        if ((sum+=c[i]) > cap) {
            sum = c[i];
            if (++cnt > m)
                return false;
        }
    return true;
}

int main() {
    while (scanf("%d%d", &n, &m)==2) {
        int lo=0, hi=0;
        for (int i=0; i<n; i++) {
            scanf("%d", c+i);
            lo=max(lo, c[i]);
            hi+=c[i];
        }

        while (lo <= hi) {
            int mid = (lo+hi)>>1;
            if (ispos(mid))
                hi = mid-1;
            else
                lo = mid+1;
        }
        printf("%d\n", hi+1);
    }
}
