#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int k;
    while ((cin >> k) && k) {
        int x, y, a, b;
        cin >> x >> y;
        while (k--) {
            cin >> a >> b;
            if (a == x || b == y)
                cout << "divisa\n";
            else cout << (b < y ? "S" : "N") << (a < x ? "O" : "E") << endl;
        }
    }
}