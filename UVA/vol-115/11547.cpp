#include <stdio.h>
#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        x = (x * 63 + 7492) * 5 - 498;
        if (x < 0) x = -x;
        cout << (x / 10) % 10 << endl;
    }
}
