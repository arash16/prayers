#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define N 51000000
unsigned int prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve()
{
    memset( prime, -1, sizeof( prime ) );

    unsigned int i;
    unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;
    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
    {
        unsigned int i2 = i + i;
        for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
    }
}

bool isPrime(int x) {
    return x==2 || (x%2==1 && gP(x));
}

int main() {
    sieve();

    char word[100];
    while(cin>>word) {
        int x = 0;
        for (int i=0; word[i]; i++)
            x+=word[i]-(word[i]<='Z' ? 'A'-26 : 'a')+1;

        cout << "It is " << (isPrime(x) ? "" : "not ") << "a prime word.\n";
    }
}
