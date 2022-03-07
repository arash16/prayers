/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 116
  Name: Unidirectional TSP
  Problem: https://onlinejudge.org/external/1/116.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int Mat[12][102],m,n;
int DP[12][102];
int P[12][102];
int y[3];
int mod(int x,int y){
    return x%y<0?x%y+y:x%y;
}
bool les(int y,int x,int z){
    return DP[y][z]<=DP[x][z];
}

int main(){
    int i,j,my,ans;
    while(scanf("%d%d",&m,&n)==2)
    {
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                cin>>Mat[i][j];

        for(i=0;i<m;i++)
            DP[i][n]=0;
        for(j=n-1;j>=0;j--)
            for(i=0;i<m;i++){
                DP[i][j]=Mat[i][j];
                y[0]=mod(i-1,m);    //upper square
                y[1]=mod(i,m);        //right square
                y[2]=mod(i+1,m);    //lower square
                sort(y,y+3);

                if(les(y[0],y[1],j+1) && les(y[0],y[2],j+1)){
                    DP[i][j]+=DP[y[0]][j+1];
                    P[i][j]=y[0];
                }
                else if(les(y[1],y[2],j+1) && les(y[1],y[0],j+1)){
                    DP[i][j]+=DP[y[1]][j+1];
                    P[i][j]=y[1];
                }
                else if(les(y[2],y[1],j+1) && les(y[2],y[0],j+1)){
                    DP[i][j]+=DP[y[2]][j+1];
                    P[i][j]=y[2];
                }
            }

        my=0;
        for(i=1;i<m;i++)
            if(DP[i][0]<DP[my][0])
                my=i;
        ans=DP[my][0];

        cout<<my+1;
        for(j=0;j<n-1;j++){
            my=P[my][j];
            cout<<" "<<my+1;
        }
        cout<<endl<<ans<<endl;
    }
}