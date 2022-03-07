/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10930
  Name: A-Sequence
  Problem: https://onlinejudge.org/external/109/10930.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool DP[35][1005];
int d[35],n;
int check(){
    for(int i=2;i<=n;i++)
        if(DP[i-1][d[i]])
            return 0;
    return 1;
}

int main(){
    int i,s,cse=1;;

    DP[0][0]=1;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
            cin>>d[i];


        for(i=1;i<=n;i++)
            for(s=0;s<=d[n];s++){
                DP[i][s]=DP[i-1][s];
                if(s>=d[i])DP[i][s]=DP[i][s]||DP[i-1][s-d[i]];
            }


        printf("Case #%d:",cse++);
        for(i=1;i<=n;i++)
            cout<<" "<<d[i];
        if(check())
            cout<<"\nThis is an A-sequence.\n";
        else
            cout<<"\nThis is not an A-sequence.\n";
    }
}