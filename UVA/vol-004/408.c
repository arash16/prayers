/*
  >>~~ ACM PROBLEM ~~<<

  ID: 408
  Name: Uniform Generator
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

#include <stdio.h>
#include <math.h>

int main()
{
     int x,y,i,t,s,I,J,R;
     while(scanf("%d%d",&x,&y)!=-1)
     {
       I=y;J=x;t=1;
       if(x>y){I=x;J=y;}
       R=I%J;
       while(R!=0)
       {
         I=J;
         J=R;
         R=I%J;
       }
       s=0;
       if(J==1)
       for(i=1;i<y;i++)
       {
         s=(s+x)%y;
         if(s==0)t=-1;
       }
       else t=-1;
       if(t>0)printf("%10d%10d    Good Choice\n\n",x,y);
       else printf("%10d%10d    Bad Choice\n\n",x,y);
     
     }
     
     return 0;
}
