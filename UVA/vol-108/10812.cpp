#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        int s, d;
        cin >> s >> d;
        if (d > s || ((s + d) % 2))
            cout << "impossible\n";
        else
            cout << (s + d)/2 << " " << (s - d)/2 << endl;
    }
}
