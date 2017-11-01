#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b) {
    return a ? gcd(b%a, a) : b;
}

int main() {
    int a, b;
    while (cin>>a && a) {
      int rs = 0;
      while (cin>>b && b)
        if (!rs) rs = fabs(a-b);
        else if (a-b)
      rs = gcd(rs, fabs(a-b));
      cout << rs << endl;
    }
}
