/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 458
  Name: The Decoder
  Problem: https://onlinejudge.org/external/4/458.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
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
