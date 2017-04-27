#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << (a / 3) * (b / 3) << endl;
    }
}