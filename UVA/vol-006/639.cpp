/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 639
  Name: Don't Get Rooked
  Problem: https://onlinejudge.org/external/6/639.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int board[5][5],mat[5][5],n;

void place(int y,int x,int t){
    int i;
    for(i=x+1;i<n && !mat[y][i];i++)board[y][i]+=t;
    for(i=x-1;i>=0 && !mat[y][i];i--)board[y][i]+=t;
    for(i=y+1;i<n && !mat[i][x];i++)board[i][x]+=t;
    for(i=y-1;i>=0 && !mat[i][x];i--)board[i][x]+=t;
}
int cnt,maxx;
void rec(int pos){
    int x,y;
    if(pos==n*n){
        if(cnt>maxx)maxx=cnt;
        return;
    }
    x=pos%n; y=pos/n;
    if(mat[y][x] || board[y][x]){
        rec(pos+1);
        return;
    }
    place(y,x,1);
    cnt++;
    rec(pos+1);
    place(y,x,-1);
    cnt--;

    rec(pos+1);
}

int main(){
    int i,j;
    while(scanf("%d",&n)==1 && n){
        maxx=cnt=0;
        for(i=0;i<n;i++){
            getchar();
            for(j=0;j<n;j++){
                if(getchar()=='X')
                    mat[i][j]=1;
                else mat[i][j]=0;
            }
        }
        rec(0);
        cout<<maxx<<endl;
    }
}