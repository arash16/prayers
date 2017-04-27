#include <stdio.h>
#include <iostream>
using namespace std;

int d(int n) {
    int sum=0;
    for(; n; n/=10) sum+=n%10;
    return sum;
}

#define MAX 1000001
bool dp[MAX];
int main(){
    int cnt=0;
    for (int i=1; i<MAX; i++) {
        if (!dp[i]) cout << i << endl;
        int x = i+d(i);
        if (x<MAX) dp[i+d(i)]=true;
    }
}
