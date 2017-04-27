#include <stdio.h>
#include <iostream>
using namespace std;

int n,m[6][6],p[6][6],best;

int check(int x,int y){
    int i,j;
    for(i=x-1;i>=0 && m[i][y]==0; i--)
        if(p[i][y])return 0;
    for(i=x+1;i<n  && m[i][y]==0; i++)
        if(p[i][y])return 0;
    for(j=y-1;j>=0 && m[x][j]==0; j--)
        if(p[x][j])return 0;
    for(j=y+1;j<n  && m[x][j]==0; j++)
        if(p[x][j])return 0;

    return 1;
}

void rec(int x,int y,int score){
    if(x>=n){
        rec(0,y+1,score);
        return;
    }
    if(y>=n){
        if(score>best)best=score;
        return;
    }

    rec(x+1,y,score);
    if(m[x][y]==0 && check(x,y)){
        p[x][y]=1;
        rec(x+1,y,score+1);
        p[x][y]=0;
    }
}

int main(){
    int i,j;
    while(scanf("%d",&n)==1 && n>0){
        for(i=0;i<n;i++){
            getchar();
            for(j=0;j<n;j++)
                m[i][j]=(getchar()=='X')?1:0;
        }
        best=0;
        rec(0,0,0);
        cout<<best<<endl;

    }
}