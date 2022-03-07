/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 483
  Name: Word Scramble
  Problem: https://onlinejudge.org/external/4/483.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char s[1000],t[1000];
    int i,k=0;
    while(gets(s)){
        for(i=0;s[i];i++)
            if(s[i]!=' ')
                t[k++]=s[i];
            else{
                while(k--)cout<<t[k];
                cout<<s[i];
                k=0;
            }
        while(k--)cout<<t[k];
        cout<<endl;
        k=0;
    }
}