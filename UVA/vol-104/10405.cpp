/*
  >>> ACM PROBLEM <<<

  ID: 10405
  Name: Longest Common Subsequence
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
*/

#include <iostream>
#include <cstring>
using namespace std;

int max(int a,int b){
    return (a>b)?a:b;
}

int main()
{
     char line1[1003],line2[1003];
     short c[1003][1003];
     int  len1,len2,i,j;

     for(i=0;i<1003;i++)
         c[i][0]=c[0][i]=0;

     while (gets(line1+1) && gets(line2+1))
     {
           len1=strlen(line1+1);
           len2=strlen(line2+1);
           for(i=1;i<=len1;i++)
             for(j=1;j<=len2;j++)
               if(line1[i]==line2[j])
                 c[i][j]=c[i-1][j-1]+1;
               else
                 c[i][j]=max(c[i-1][j],c[i][j-1]);

           cout<<c[len1][len2]<<endl;
     }
  return 0;
}
