/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10013
  Name: Super long sums
  Problem: https://onlinejudge.org/external/100/10013.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

int main()
{
 int tn,n,i;
 char n1[1000001],n2[1000001];
 scanf("%d",&tn);
 while(tn--)
 {
   memset(n1,0,sizeof(n1));
   memset(n2,0,sizeof(n2));

   scanf("%d",&n);
   for(i=1;i<=n;i++)
     scanf("%d%d",&n1[i],&n2[i]);
   for(i=n;i;i--)
   {
     n1[i]+=n2[i];
     if(n1[i]>9)
     {
       n1[i-1]++;
       n1[i]-=10;
     }
   }

   if(n1[0])printf("%d",n1[0]);
   for(i=1;i<=n;i++)
     printf("%d",n1[i]);

   printf("\n");
   if(tn)printf("\n");
 }
 return 0;
}
