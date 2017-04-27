#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int mat[102][102],c,r;

int memo[102][102];
int best(int y,int x){
    if(x<0 || x>=c || y<0 || y>=r)return 0;  //out of bound
    if(memo[y][x]!=-1)return memo[y][x];

    int t1,t2,t3,t4;
    t1=t2=t3=t4=0;
    if(mat[y][x]>mat[y][x+1])
        t1=best(y,x+1);  //go right

    if(mat[y][x]>mat[y][x-1])
        t2=best(y,x-1);  //go left

    if(mat[y][x]>mat[y+1][x])
        t3=best(y+1,x);  //go up

    if(mat[y][x]>mat[y-1][x])
        t4=best(y-1,x);  //go down

    return memo[y][x]=max(max(max(t1,t2),t3),t4)+1;
}

int main(){
    char name[1000];
    int T,i,j,m;

    cin>>T;
    while(T--){
        scanf("%s%d%d",name,&r,&c);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                cin>>mat[i][j];

        memset(memo,-1,sizeof(memo));
        int m=0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                m=max(m,best(i,j));

        printf("%s: %d\n",name,m);
    }
}