/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 195
  Name: Anagram
  Problem: https://onlinejudge.org/external/1/195.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct les{
    bool operator()(char s1, char s2)const{
        if(toupper(s1)==toupper(s2))
            return s1<s2;
        return toupper(s1)<toupper(s2);
    }
};
int main(){
    int T,l;
    char s[100];

    scanf("%d\n",&T);
    while(T--){
        gets(s);
        l=strlen(s);
        sort(s,s+l,les());
        do{
            puts(s);
        }while(next_permutation(s,s+l,les()));
    }
}