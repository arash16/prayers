#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

map<int,int> m;
int a[100000000];

int main(){
    int t,i,n=0;
    while(scanf("%d",&t)==1){
        if(m.count(t)==0)
            a[n++]=t;
        m[t]++;
    }
    for(i=0;i<n;i++)
        printf("%d %d\n",a[i],m[a[i]]);
}