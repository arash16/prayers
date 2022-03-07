/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1213
  Name: Sum of Different Primes
  Problem: https://onlinejudge.org/external/12/1213.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <bits/stdc++.h>
using namespace std;

int primes[200], pcn;
bool isnp[1143];
void sieve() {
    isnp[0] = isnp[1] = 1;
    for (int i=2; i<=1143; ++i)
        if (!isnp[i]) {
            primes[pcn++] = i;
            for (int j=i+i; j<=1143; j+=i)
                isnp[j] = 1;
        }
}

int DP[16][200][1143];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    sieve();

    for (int pi=0; pi<pcn; ++pi)
        for (int i=pi; i<pcn; ++i)
            DP[1][pi][primes[i]] = 1;

    for (int k=2; k<15; ++k)
        for (int pi=pcn-1; pi>=0; --pi)
            for (int x=primes[pi]; x<1143; ++x)
                DP[k][pi][x] = DP[k-1][pi+1][x-primes[pi]] + DP[k][pi+1][x];

    int n, k;
    while (cin >> n >> k && (n||k))
        cout << DP[k][0][n] << endl;
}
