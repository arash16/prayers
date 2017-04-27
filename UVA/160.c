/*
  >>~~ ACM PROBLEM ~~<<

  ID: 160
  Name: Factors and Factorials
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

#include <stdio.h>

int nextprime(int n)
{
  int i;
  while(n>1)
  {
    n++;
    for(i=2;i<=sqrt(n);i++)
      if(n%i==0)
        goto ss;
    return n;
    ss:;
  }
  return 0;
}



int main()
{
 int n,i,t,x,line,lastp,max;
 short c[101];
 
 while (scanf("%d",&n)!=EOF)
 {
   if(n==0)break;
   memset(c,0,sizeof(c));
   for(i=2;i<=n;i++)
   {
     t=i;
     lastp=2;
     x=0;
     while(lastp<=i)
     {
       while(t%lastp==0)
       {
         t=(int)(t/lastp);
         c[x]++;
       }
       lastp=nextprime(lastp);
       x++;
     }
   }


   line=0;
   printf("%3d! =",n);
   for(i=0;c[i];i++)
   {     
     if(line==15)
     {
       printf("\n      ");
       line=0;
     }
     line++;
     printf("%3d",c[i]);
   }
   printf("\n");
 }
 return 0;
}
