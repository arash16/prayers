#include <stdio.h>

int main() {
    int n, a, b, t;
    while (scanf("%d", &n)==1 && n) {
        a = b = 0;
        while (n) {
            t = n & -n;
            a |= t;
            n -= t;
            t = n & -n;
            b |= t;
            n -= t;
        }
        printf("%d %d\n", a, b);
    }
}
