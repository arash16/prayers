/*
  >>~~ ACM PROBLEM ~~<<

  ID: 151
  Name: Power Crisis
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

char isright(int n,int m)
{
 char a[101];
 int i,j,k;
 memset(a,0,sizeof(a));
 j=1;
 for(i=1;i<n;i++)
 {
   if(j==13)return 0;
   a[j]=1;
   k=0;
   while(k<m)
   {
     j++;
     if(j>n)j=j-n;
     if(a[j])continue;
     k++;
   }
 }
 return 1;
}

int main()
{
 int n,m;
 while (scanf("%d",&n)!=-1)
 {
   if(!n)break;
   for(m=1;m<n;m++)
     if(isright(n,m))break;
   printf("%d\n",m);
 }
 return 0;
}
