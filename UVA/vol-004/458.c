/*
  >>~~ ACM PROBLEM ~~<<

  ID: 458
  Name: The Decoder
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

#include <stdio.h>
int main()
{
 char c;
 while ((c=getchar())!=EOF)
 {
   (c==10)?putchar(c):putchar(c-7);
 }
 return 0;
}
