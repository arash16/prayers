/*
  >>> ACM PROBLEM <<<
  
  ID: 572
  Name: Oil Deposits
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
*/

#include <iostream>
#include <cstring>
using namespace std;

char dep[105][105];
void rec(int x,int y);

int main()
{
     int m,n,i,j,count;

     while ((scanf("%d%d",&m,&n)!=-1) && m && n)
     {
        for(i=1;i<=m;i++)
          scanf("%s\n",dep[i]+1);

        count=0;
        for(i=1;i<=m;i++)
          for(j=1;j<=n;j++)
            if(dep[i][j]=='@'){
              count++;
              rec(i,j);
            }

        cout<<count<<endl;
     }
     return 0;
}

void rec(int x,int y){
     int i,j;
     dep[x][y]=0;
     for(i=x-1;i<x+2;i++)
       for(j=y-1;j<y+2;j++)
         if(dep[i][j]=='@')rec(i,j);
}
