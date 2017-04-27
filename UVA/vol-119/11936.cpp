#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, a[3];
    cin>>n;
    while(n--) {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        cout << (a[0]+a[1]<=a[2] ? "Wrong!!\n" : "OK\n");
    }
}
