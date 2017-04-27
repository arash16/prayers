/*
  >>~~ ACM PROBLEM ~~<<

  ID: 441
  Name: Lotto
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

int s[13],k[7];
int n,t;

void rec(int p)
{
  int i;
  if(p<7)
  for(i=k[p-1]+1;i<=n;i++)
  {
    k[p]=i;
    rec(p+1);
  }
  else
  {
    printf("%d %d %d %d %d %d\n",s[k[1]],s[k[2]],s[k[3]],
                               s[k[4]],s[k[5]],s[k[6]]);
  }
}

int main()
{
 int i;
 t=0;
 while (scanf("%d",&n)!=-1)
 {
   if(!n)break;
   if(t==1)printf("\n");
   t=1;
   for(i=1;i<=n;i++)
     scanf("%d",&s[i]);
   rec(1);
 }
 return 0;
}
