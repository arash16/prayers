/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 986
  Name: How Many?
  Problem: https://onlinejudge.org/external/9/986.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int n,r,k;

long long memo[44][44][22];
long long f(int x,int y,int r){
    if(y<0)return 0;
    if(x==2*n && y==0 && r==0)return 1;
    if(x==2*n)return 0;

    long long &ans=memo[x][y][r];
    if(ans==-1){
        if(y==k-1)
            if(r>0)
                ans=f(x+2,y,r-1)+f(x+2,y+2,r)+f(x+1,y-1,r);
            else
                ans=f(x+2,y+2,r)+f(x+1,y-1,r);
        else
            ans=f(x+1,y+1,r)+f(x+1,y-1,r);
    }
    return ans;
}

//------------------------------------------
long long DP[44][44][22];
long long dp(int x,int y,int r){
    if(y<0)return 0;
    return DP[x][y][r];
}
//------------------------------------------

int main(){
    int x,y,rp;
    while(scanf("%d%d%d",&n,&r,&k)==3){
        //memset(memo,-1,sizeof(memo));
        //cout<<f(0,0,r)<<endl;         //memoization is faster

        memset(DP,0,sizeof(DP));
        DP[2*n][0][0]=1;
        for(x=2*n-1;x>=0;x--)
            for(y=0;y<=n;y++)
                for(rp=0;rp<=r;rp++)
                    if(y==k-1)
                        DP[x][y][rp]=(rp>0 ? dp(x+2,y,rp-1) : 0)+
                                             dp(x+2,y+2,rp)     +
                                             dp(x+1,y-1,rp);
                    else
                        DP[x][y][rp]=dp(x+1,y+1,rp)+
                                     dp(x+1,y-1,rp);
        cout<<DP[0][0][r]<<endl;
    }
}