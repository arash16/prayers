/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10340
  Name: All in All
  Problem: https://onlinejudge.org/external/103/10340.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
     char s[1000000],t[1000000];
     long slen,tlen,i,j;
     while (cin>>s>>t)
     {
           slen=strlen(s);tlen=strlen(t);
           i=j=0;
           for(;i<slen;i++){
             for(;j<tlen;j++)
               if(s[i]==t[j]){j++;goto t;}
             if(j==tlen)
               break;
             t:;
           }

           if(i==slen)
             cout<<"Yes";
           else
             cout<<"No";
           cout<<endl;
     }
  return 0;
}
