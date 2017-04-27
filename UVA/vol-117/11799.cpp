#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int C;
    cin >> C;
    for (int c = 1; c <= C; c++) {
        int n, x; cin >> n;
        int max = 0;
        while (n--) {
            cin >> x;
            if (x > max) max = x;
        }

        printf("Case %d: %d\n", c, max);
    }
}