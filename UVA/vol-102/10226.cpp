/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10226
  Name: Hardwood Species
  Problem: https://onlinejudge.org/external/102/10226.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;

void toup(char* s){
    for(;*s;s++)
        *s=toupper(*s);
}

int main(){
    int n,count;
    string name;
    char t[40];
    scanf("%d\n\n",&n);
    map<string,int> list;
    map<string,int>::iterator ii;
    while(n--){
        count=0;
        while(gets(t) && t[0]){
            name=t;
            list[name]++;
            count++;
        }
        for(ii=list.begin();ii!=list.end();ii++)
            printf("%s %.4f\n",&ii->first[0],((float)ii->second/count)*100);
        if(n)printf("\n");
        list.clear();
    }
    return 0;
}