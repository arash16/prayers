#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

#define bit(i,n) (n&(1<<i))

int memo[1<<15],v[15],n;

int rec(int avail){
    int &ans=memo[avail];
    int i,j,k;

    if(ans==-1){
        ans=0;
        for(int i=0;i<n;i++)
            if(bit(i,avail)){
                //ans=max(ans,rec(avail & ~(1<<i)));
                for(j=i+1;j<n;j++)
                    if(bit(j,avail))
                        for(k=j+1;k<n;k++)
                            if(bit(k,avail))
                                if(v[i]+v[j]+v[k]>=20)
                                    ans=max(ans,1+rec(avail & ~(1<<i) & ~(1<<j) & ~(1<<k)));
                //break;
            }
    }
    return ans;
}

int main(){
    int i,cse=1;
    while(scanf("%d",&n)==1 && n){
        for(i=0;i<n;i++)
            cin>>v[i];
        memset(memo,-1,sizeof memo);
        printf("Case %d: %d\n",cse++,rec((1<<n)-1));
    }
}