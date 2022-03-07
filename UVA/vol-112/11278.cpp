/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11278
  Name: One-Handed Typist
  Problem: https://onlinejudge.org/external/112/11278.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

char qwerty[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?\n\t ",
     dvorak[] = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"\n\t ",
     mp[127], ch;
int main(){
    for (int i=0; qwerty[i]; i++)
        mp[qwerty[i]] = dvorak[i];
    while ((ch = getchar()) != EOF)
        putchar(mp[ch] ? mp[ch] : ch);
}
