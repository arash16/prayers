#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    long long int n, sq;
    while(cin>>n && n) {
        sq = ceil(sqrt((long double)n));
        int x, y, d = sq*sq - n;

        if (d < sq) x=sq, y=d+1;
        else y=sq, x=2*sq-d-1;
        printf("%d %d\n", (sq&1)?y:x, (sq&1)?x:y);
    }
}
