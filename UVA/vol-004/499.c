/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 499
  Name: What's The Frequency, Kenneth?
  Problem: https://onlinejudge.org/external/4/499.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

int main()
{
 int i,max;
 char c;
 char letters[58];

 memset(letters,0,sizeof(letters));
 max=0;
 while ((c=getchar())!=-1)
 {
   if(c=='\n')
   {
     for(i=0;i<60;i++)
       if(letters[i]==max)printf("%c",i+65);
     printf(" %d\n",max);
     memset(letters,0,sizeof(letters));
     max=0;
   }
   if(!isalpha(c))continue;
   letters[c-65]++;
   if(letters[c-65]>max)max=letters[c-65];
 }
 return 0;
}
