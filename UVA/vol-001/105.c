/*
  >>~~ ACM PROBLEM ~~<<

  ID: 105
  Name: The Skyline Problem
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/


int main()
{
 int s,h,e,i,cu,t;
 int A[10001];
 
 memset(A,0,sizeof(A));
 while (scanf("%d%d%d",&s,&h,&e)!=-1)
   for(i=s;i<e;i++)
    if(h>A[i])
     A[i]=h;
     
 cu=0;t=0;
 for(i=0;i<10001;i++)
   if(A[i]!=cu)
   {
     if(t)printf(" ");
     else t=1;
     printf("%d %d",i,A[i]);
     cu=A[i];
   }
 printf("\n");
 return 0;
}
