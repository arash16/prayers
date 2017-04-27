#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int N, n;
    cin >> N;
    for (int n = 1; n <= N; n++) {
        int a, b, result;
        cin >> a >> b;
        if (a % 2 == 0) a++;
        if (b % 2 == 0) b--;
        if (a > b) result = 0;
        else if (a == b) result = a;
        else result = ((a + b) * (b - a + 2)) >> 2;

        printf("Case %d: %d\n", n, result);
    }
}