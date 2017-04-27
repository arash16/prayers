#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

#define N 3000
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


int main(){
    sieve();
    char line[3000];
    int cc[128];
    int T, f;
    cin>>T;
    for(int cse=1; cse<=T; cse++) {
        cin>>line;
        for (int i=0; i<26; i++)
            cc['a'+i] = cc['A'+i] = cc['0'+i] = 0;

        for (int i=0; line[i]; i++)
            cc[line[i]]++;

        bool empty = true;
        printf("Case %d: ", cse);
        for (int i='0'; i<='z'; i++)
            if ((f = cc[i])>1)
                if (f==2 || (f&1 && gP(f))) {
                    cout << (char)i;
                    empty = false;
                }
        cout << (empty ? "empty\n" : "\n");
    }
}
