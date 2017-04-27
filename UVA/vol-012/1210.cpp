#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXP 10001
bool nisp[MAXP] = {1, 1};
int cump[MAXP]={2}, pcnt=1;
void sieve() {
    for (int i=3; i<MAXP; i+=2)
        if (!nisp[i]) {
            cump[pcnt] = cump[pcnt-1] + i;
            for (int j=i*i; j<MAXP; j+=i)
                nisp[j] = 1;
            ++pcnt;
        }
}

int DP[MAXP];
int main() {
    sieve();
    for (int i=0; i<pcnt; i++) {
        if (cump[i]<MAXP)
            DP[cump[i]] = 1;

        for (int j=i-1; j>=0 && cump[i]-cump[j]<MAXP; j--)
            ++DP[cump[i]-cump[j]];
    }

    int n;
    while (scanf("%d", &n)==1 && n)
        printf("%d\n", DP[n]);
}
