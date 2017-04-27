/*
  >>> ACM PROBLEM <<<
  
  ID: 344
  Name: Roman Digititis
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
   int c[5][101],i,j,t,n;
   memset(c,0,sizeof(c));
   
   for(i=0;i<101;i++)
     for(j=0;j<5;j++)
       c[j][i]=0;
   for(i=1;i<101;i++)
     {
        t=i % 10;
        for(j=0;j<3;j+=2)
        {
          if(t>0 && t<4)   c[0+j][i]+=t;
          if(t>5 && t<9)   c[0+j][i]+=t-5;
          if(t==4 || t==9) c[0+j][i]+=1;
          if(t>3 && t<9)   c[1+j][i]+=1;
          if(t==9)         c[2+j][i]+=1;
          
          t=i/10;
        }
        if(i==100)c[4][i]=+1;
        for(j=0;j<5;j++)
          c[j][i]+=c[j][i-1];
     }
   while (cin>>n && n)
   {
   printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,c[0][n]
                                                ,c[1][n]
                                                ,c[2][n]
                                                ,c[3][n]
                                                ,c[4][n]);
   }
   return 0;
}
