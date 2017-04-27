#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n, i;
    while (cin >> n) {
        int r = 1;
        for (i = 1; r % n; i++)
            r = (r * 10 + 1) % n;
        cout << i << endl;
    }
}