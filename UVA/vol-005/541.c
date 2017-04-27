/*
  >>~~ ACM PROBLEM ~~<<

  ID: 541
  Name: Error Correction
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/


int main()
{
 int n,i,j,t,x,y;
 char row[100],col[100];
 while (scanf("%d",&n)!=-1)
 {
   if(!n)break;
   memset(row,0,sizeof(row));
   memset(col,0,sizeof(col));
   for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     {
       scanf("%d",&t);
       row[i]+=t;
       col[j]+=t;
     }
   x=y=0;
   for(i=1;i<=n;i++)
     if(row[i]%2==1)
       if(!y)y=i;
       else goto cor;
   for(j=1;j<=n;j++)
     if(col[j]%2==1)
       if(!x)x=j;
       else goto cor;
       
   if(!x && !y)
     printf("OK\n");
   else
     printf("Change bit (%d,%d)\n",y,x);
   continue;
   cor:
   printf("Corrupt\n");
 }
 return 0;
}
