/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 530
  Name: Binomial Showdown
  Problem: https://onlinejudge.org/external/5/530.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

int bcd(int I,int J)
{
  int t,R;
  if(J>I){t=J;J=I;I=t;}
  R=I%J;
  while(R!=0)
  {
    I=J;
    J=R;
    R=I%J;
  }
  return J;
}
int main()
{
  int n,k,i,j;
  int res[20],ma[20],r,bc;
  while(scanf("%d%d",&n,&k)!=-1)
  {
    if(n==0 && k==0)break;
    for(i=0;i<20;i++)
    {
      res[i]=1;
      ma[i]=1;
    }
    if(k<n/2)k=n-k;
    for(i=k+1;i<=n;i++)
      res[i-k-1]=i;
    for(i=2;i<=n-k;i++)
      ma[i]=i;
    for(i=0;i<=n-k;i++)
      for(j=0;j<=n-k;j++)
      {
        bc=bcd(res[i],ma[j]);
        res[i]/=bc;
        ma[j]/=bc;
      }
    r=1;
    for(i=0;i<20;i++)
      r*=res[i];
    printf("%d\n",r);
  }
  return 0;
}
