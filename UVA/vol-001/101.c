/*
  >>~~ ACM PROBLEM ~~<<

  ID: 101
  Name: Blocks
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

#include <stdio.h>
char blocks[30][30];
int n;

char srch(int block,int *x,int *y,int *d)
{
 int i,j,k;
 for(i=0;i<n;i++)
  for(j=0;j<=n;j++)
   if(blocks[i][j]==block)
   {
     *x=j;
     *y=i;
     *d=0;
     for(k=j;blocks[i][k]!=-1;k++)(*d)++;
     return 1;
   }
   else if(blocks[i][j]==-1)break;
   return 0;
}

char count(int y)
{
  int i;
  for(i=0;blocks[y][i]!=-1;)i++;
  return i;
}

void moveInital(int x,int y)
{
 int b;
 if(blocks[y][x]==-1)return;
 b=blocks[y][x];
 blocks[b][count(b)]=b;
 blocks[y][x]=-1;
 moveInital(x+1,y);
}

int main()
{
 int i,j;
 int x1,x2,y1,y2,d1,d2,b1,b2;
 char c1[5],c2[5];
 char temp[25];
 

 scanf("%d",&n);
 
 memset(blocks,-1,sizeof(blocks));
 for(i=0;i<n;i++)
   blocks[i][0]=i;
 
 while (scanf("%s%d%s%d",&c1,&b1,&c2,&b2)!=EOF)
 {
   srch(b1,&x1,&y1,&d1);
   srch(b2,&x2,&y2,&d2);
   if(c1[0]=='q')break;
   if(y1==y2 || b1==b2)continue;
   if(c1[0]=='m'){
     if(c2[1]=='n')
     {
       moveInital(x1+1,y1);
       moveInital(x2+1,y2);
       blocks[y2][x2+1]=b1;
       blocks[y1][x1]=-1;
     }
     else if(c2[1]=='v')
     {
       moveInital(x1+1,y1);
       blocks[y2][count(y2)]=b1;
       blocks[y1][x1]=-1;
     }
   }
   if(c1[0]=='p'){
     if(c2[1]=='n')
     {
       moveInital(x2+1,y2);
       memcpy(&blocks[y2][x2+1],&blocks[y1][x1],sizeof(char)*d1);
       memset(&blocks[y1][x1],-1,sizeof(char)*d1);
     }
     else if(c2[1]=='v')
     {
       memcpy(&blocks[y2][count(y2)],&blocks[y1][x1],sizeof(char)*d1);
       memset(&blocks[y1][x1],-1,sizeof(char)*d1);
     }
   }
 }
 for(i=0;i<n;i++)
 {
   printf("%d:",i);
   for(j=0;j<n;j++)
     if(blocks[i][j]!=-1)
       printf(" %d",blocks[i][j]);
   printf("\n");
 }

 return 0;
}
