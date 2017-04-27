#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int val[127];
unsigned long long MODULUS;
void newModulus() {
    MODULUS = (unsigned long long)rand() * rand();
}

long long conv(const char num[], const int bf) {
    long long result = 0;
    for (int i=0; num[i]; i++)
        result = (result*bf + val[num[i]]) % MODULUS;
    return result;
}

int minbase(const char num[]) {
    int mn = 2;
    for (int i=0; num[i]; i++)
        if (val[num[i]] >= mn)
            mn = val[num[i]]+1;
    return mn;
}


int main(){
    char ds[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0; ds[i]; i++)
        val[ds[i]] = i;

    newModulus();
    char w1[20000], w2[20000];
    while (cin>>w1>>w2) {
        int m1 = minbase(w1),
            m2 = minbase(w2);

        for (int i=m1; i<=36; i++) {
            long long x = conv(w1, i);

            for (int j=m2; j<=36; ++j) {
                long long r = conv(w2, j);
                if (x == r) {
                    // double check with another modulus
                    newModulus();
                    if ((x=conv(w1, i)) == conv(w2, j)) {
                        printf("%s (base %d) = %s (base %d)\n", w1, i, w2, j);
                        goto fin;
                    }
                }
            }
        }

        printf("%s is not equal to %s in any base 2..36\n", w1, w2);
        fin:;
    }
}
