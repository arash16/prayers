#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long long int sum=0;
        while(n--) {
            int sz, an, fr;
            cin>>sz>>an>>fr;
            sum += sz*fr;
        }
        cout<<sum<<endl;
    }
}
