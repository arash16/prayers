#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define N 66000
unsigned int prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
void sieve() {
    memset(prime, -1, sizeof(prime));
    unsigned int i, i2, sqrtN = (unsigned int)sqrt((double)N) + 1;
    for(i = 3; i<sqrtN; i+=2)
        if(gP(i)) {
            i2 = i + i;
            for(unsigned int j = i*i; j<N; j+= i2)
                prime[j>>6] &= ~(1<<((j>>1)&31));
        }
}

bool isPrime(int n) {
    return n==2 || ((n&1) && gP(n));
}

int powmod(int b, int p, int m) {
    if (!p) return 1;
    if (p==1) return b%m;

    long long int h = powmod(b, p>>1, m);
    return ((p&1) ? h*((b*h)%m) : h*h)%m;
}

bool fermat(int n, int a) {
    return powmod(a, n, n) == a;
}

bool isC[65001];
bool isCarmichael(int n) {
    if (isPrime(n)) return false;
    for(int i=2; i<n; i++)
        if (!fermat(n, i))
            return false;
    return true;
}

int main(){
    sieve();

    /*
    int cnt=0;
    for (int i=0; cnt<120 && i<65000; i++)
        if (isCarmichael(i))
            printf("#%d: %d\n", ++cnt, i);
    */

    int n;
    while(cin>>n && n)
        printf(isCarmichael(n) ? "The number %d is a Carmichael number.\n" : "%d is normal.\n", n);
}

// high probablity: sum of digits is zero
/*
#include <stdio.h>
#include <iostream>
using namespace std;

bool isC[65001];
int main(){
    int n;
    isC[561]=isC[1105]=isC[1729]=isC[2465]=isC[2821]=isC[6601]=
    isC[8911]=isC[10585]=isC[15841]=isC[29341]=isC[41041]=
    isC[46657]=isC[52633]=isC[62745]=isC[63973]=true;
    while(cin>>n && n)
        printf(isC[n] ? "The number %d is a Carmichael number.\n" : "%d is normal.\n", n);
}
*/
