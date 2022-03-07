/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10252
  Name: Common Permutation
  Problem: https://onlinejudge.org/external/102/10252.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

int min(int x, int y){
    return (x<y)?x:y;
}

int main()
{
    int len,i,j;
    char b1[1005],b2[1005];
    while(gets(b1) && gets(b2)){
      int counts1[30]={0},counts2[30]={0};
      len=strlen(b1);
      for(i=0;i<len;i++)
        counts1[b1[i]-'a']++;
      len=strlen(b2);
      for(i=0;i<len;i++)
        counts2[b2[i]-'a']++;

      for(i=0;i<26;i++)
        for(j=0;j<min(counts1[i],counts2[i]);j++)
          cout<<(char)(i+'a');
      cout<<endl;
    }
    return 0;
}
