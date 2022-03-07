/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 490
  Name: Rotating Sentences
  Problem: https://onlinejudge.org/external/4/490.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
     char lines[105][105];
     int i=0,j,maxlen=0,t;
     while (gets(lines[i])){
           if((t=strlen(lines[i]))>maxlen)maxlen=t;
           for(j=t;j<105;j++)lines[i][j]=' ';
           i++;
     }
     t=i-1;
     for(j=0;j<maxlen;j++){
       for(i=t;i>=0;i--)
         cout<<lines[i][j];
       cout<<endl;
     }
  return 0;
}
