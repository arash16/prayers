/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10008
  Name: What's Cryptanalysis?
  Problem: https://onlinejudge.org/external/100/10008.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

int main()
{
 int n,i,j,k,max,maxp;
 char line[2048],letters[26];
 scanf("%d",&n);
 memset(letters,0,sizeof(letters));
 for(i=0;i<=n;i++)
 {
   gets(line);
   for(j=0;line[j];j++)
   {
     k=26;
     if(line[j]>64 && line[j]<91)
       k=line[j]-65;
     else if(line[j]>96 && line[j]<123)
       k=line[j]-97;
     if(k!=26)
       letters[k]++;
   }
 }
 for(i=0;i<26;i++)
 {
   max=0;
   for(j=0;j<26;j++)
     if(letters[j]>max)
     {
       max=letters[j];
       maxp=j;
     }
   if(max)
     printf("%c %d\n",maxp+65,letters[maxp]);
   letters[maxp]=0;
 }
 return 0;
}
