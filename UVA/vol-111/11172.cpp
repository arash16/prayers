#include <stdio.h>
#include <iostream>
using namespace std;

void main() {
    int n;
    cin >> n;
    while (n--) {
        long long int x, y;
        cin >> x >> y;
        cout << (x<y ? "<" : x > y ? ">" : "=") << endl;
    }
}
