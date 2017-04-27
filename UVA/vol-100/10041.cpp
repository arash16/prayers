#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int a[506];
int main(){
    int n,T,s,i;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        s=0;
        for(i=0;i<n;i++)
            s+=abs(a[i]-a[n/2]);
        cout<<s<<endl;
    }
}