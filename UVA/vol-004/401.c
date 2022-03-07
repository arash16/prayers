/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 401
  Name: Palindromes
  Problem: https://onlinejudge.org/external/4/401.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <string.h>

int main(){
 char line[25];
 char r[92];
 int pal,rev,i,len;

 for(i=0;i<92;i++)
   r[i]=0;
 r['A']='A';r['E']='3';  r['H']='H';r['I']='I';  r['J']='L';r['L']='J';
 r['M']='M';r['O']='O';  r['S']='2';r['T']='T';  r['U']='U';r['V']='V';
 r['W']='W';r['X']='X';  r['Y']='Y';r['Z']='5';  r['1']='1';r['2']='S';
 r['3']='E';r['5']='Z';  r['8']='8';

 while (gets(line)){
    len=strlen(line);
    pal=rev=1;
    for(i=0;i<(float)len/2;i++)
    {
      if(line[i]!=line[len-i-1])     pal=0;
      if(line[i]!=r[line[len-i-1]])  rev=0;
    }
    if(!pal && !rev)printf("%s -- is not a palindrome.",line);
    if(pal && !rev) printf("%s -- is a regular palindrome.",line);
    if(!pal && rev) printf("%s -- is a mirrored string.",line);
    if(pal && rev)  printf("%s -- is a mirrored palindrome.",line);
    printf("\n\n");
 }
 return 0;
}
