#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int m, x, v;
    while (scanf("%d%d", &m, &x)==2 && (m||x)) {
        long long v = (m-1)/(1-x/100.0) - 1e-3;
        if (v < m) puts("Not found");
        else printf("%lld\n", v);
    }
}
