#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int f(int n) {
    if (n==1) return 1;

    int t = (f(n>>1) + (n&1)) << 1;
    return ((t-1)%(n&(~1))) + 1;
}

int main() {
    int n;
    while (cin>>n && n)
        cout << f(n) << endl;
}
