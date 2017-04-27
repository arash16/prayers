#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

int sameDigits(int x, int y) {
    int cnt = 0;
    for (int i=0; i<4; i++) {
        if (x%10 == y%10)
            cnt++;
        x/=10; y/=10;
    }
    return cnt;
}

int hasDigits(int x, int y) {
    int hass[] = {0,0,0,0,0,0,0,0,0,0};

    if (hass[0] || hass[1] || hass[2])
        cout << "!";

    for (int i=0; i<4; i++) {
        hass[y%10]++;
        y /= 10;
    }

    int cnt=0;
    for (int j=0; j<4; j++) {
        if (--hass[x%10] >= 0) cnt++;
        x /= 10;
    }

    return cnt;
}

int poss[10000];
int main() {
    int T, n, x, num, cp, ce, scnt, hcnt;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int sz = 10000;
        for (int i=0; i<10000; i++)
            poss[i] = i;

        for (int i=0; i<n; i++) {
            scanf("%d %d/%d", &num, &cp, &ce);
            int j=0;
            for (int k=0; k<sz; k++) {
                x = poss[k];
                scnt = sameDigits(num, x);
                if (scnt == cp) {
                    hcnt = hasDigits(num, x);
                    if (hcnt == ce+cp)
                        poss[j++] = x;
                }
            }
            sz = j;
        }

        if (!sz)
            puts("impossible");
        else if (sz==1)
            printf("%04d\n", poss[0]);
        else
            puts("indeterminate");
    }
}
