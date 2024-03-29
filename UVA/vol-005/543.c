/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 543
  Name: Goldbach's Conjecture
  Problem: https://onlinejudge.org/external/5/543.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

char isprime(int n)
{
  int i;
  for(i=2;i<=sqrt(n);i++)
    if(n%i==0)return 0;
  return 1;
}

int main()
{
 int n,f,i;
 while (scanf("%d",&n)!=-1)
 {
   if(!n)break;

   f=0;
   for(i=2;i<n;i++)
   {
     if(isprime(n-i) && isprime(i))
     {
       f=i;
       break;
     }
   }
   if(f)printf("%d = %d + %d\n",n,f,n-f);
   else printf("Goldbach's conjecture is wrong.\n");
 }
 return 0;
}
