/*
  >>~~ ACM PROBLEM ~~<<

  ID: 494
  Name: Kindergarten Counting Game
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
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
