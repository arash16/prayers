#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int a[5];
int used[5];
bool BT(int i, int n)
{
    if(i==5)
        return (n==23);

    for(int j=0; j<5; j++)
        if(!used[j])
        {
            used[j]=1;
            if(BT(i+1,n+a[j]))return true;
            if(i && BT(i+1,n-a[j]))return true;
            if(i && BT(i+1,n*a[j]))return true;
            used[j]=0;
        }

    return false;
}

int main()
{
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4] && (a[0]||a[1]||a[2]||a[3]||a[4]))
    {
        memset(used,0,sizeof(used));
        if(BT(0,0))
            puts("Possible");
        else
            puts("Impossible");
    }
}