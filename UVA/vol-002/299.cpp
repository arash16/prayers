#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int C;
    cin >> C;
    while (C--) {
        int n, a[50], result = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        for (int i =0; i<n; i++)
            for (int j=0; j<n-1; j++)
                if (a[j] > a[j + 1]) {
                    result++;
                    a[j] = a[j] ^ a[j + 1];
                    a[j + 1] = a[j] ^ a[j + 1];
                    a[j] = a[j] ^ a[j + 1];
                }

        printf("Optimal train swapping takes %d swaps.\n", result);
    }
}