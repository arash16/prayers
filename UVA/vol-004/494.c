/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 494
  Name: Kindergarten Counting Game
  Problem: https://onlinejudge.org/external/4/494.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>

char count_word(char word[])
{
  int i,t;
  t=0;
  for(i=0;word[i];i++)
    if((word[i]>64 && word[i]<91)||(word[i]>96 && word[i]<123))
      t=1;
    else if(word[i]!='\n')
      return t + count_word(word+i+1);

  return t;
}


int main()
{
 char line[1000000];

 while (gets(line))
   printf("%d\n",count_word(line));

 return 0;
}
