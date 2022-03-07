/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10490
  Name: Mr. Azad and his Son!!!!!
  Problem: https://onlinejudge.org/external/104/10490.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;


int P[] = { 2, 3, 5, 7, 13, 17, 19, 31 };
bool ip[32];

bool isprime(int x) {
    for (int i=2; i<x; ++i)
        if (x%i==0)
            return 0;
    return 1;
}

int main() {
    for (int i=0; i<8; ++i)
        ip[P[i]] = 1;

    int n;
    while (cin >> n && n) {
        if (!ip[n])
            if (isprime(n))
                cout << "Given number is prime. But, NO perfect number is available.\n";
            else
                cout << "Given number is NOT prime! NO perfect number is available.\n";
        else
            printf("Perfect: %lld!\n", (1LL<<(n-1)) * ((1LL<<n)-1));
    }
}
