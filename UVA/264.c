/*
  >>~~ ACM PROBLEM ~~<<

  ID: 264
  Name: Count on Cantor
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/


int main()
{
 long int cases,x,y,m,n,i;

 while (scanf("%ld",&cases)!=-1)
 {
   m=1;
   n=-1;
   x=y=1;
   for(i=1;i<cases;i++)
   {
     x+=n;
     y+=m;
     if(x<1)
      {
        x=n=1;
        m=-1;
      }
     if(y<1)
     {
       y=m=1;
       n=-1;
     }
   }
   printf("TERM %ld IS %ld/%ld\n",cases,x,y);
 }
 return 0;
}
