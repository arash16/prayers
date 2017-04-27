#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int count(int n) {
    int cnt = 0;
    int sq = sqrt((double)n);
    for (int i=2; i<=sq; i++)
        if (n%i==0) {
            cnt++;
            while (n%i==0)n/=i;
            sq = sqrt((double)n);
        }
    return cnt+(n>1);
}

int main(){
    int n;
    while(cin>>n && n)
        printf("%d : %d\n", n, count(n));
}
