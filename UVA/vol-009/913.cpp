#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    long long int n;
    while(cin>>n) {
        long long t = (n+1)*((n+1)>>1)-1;
        cout << 3*t - 6 <<endl;
    }
}

