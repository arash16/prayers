/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 628
  Name: Passwords
  Problem: https://onlinejudge.org/external/6/628.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;


char dic[101][270];
int dicnt;
char rule[270];
int tmp[270];

void BT(int i)
{
    int j;
    if(rule[i]==0)
    {
        for(j=0; rule[j]; j++)
            if(tmp[j]<10)
                cout<<tmp[j];
            else
                cout<<dic[tmp[j]-10];
        cout<<endl;
        return;
    }

    if(rule[i]=='0')
        for(j=0; j<10; j++)
        {
            tmp[i]=j;
            BT(i+1);
        }
    else
        for(j=0; j<dicnt; j++)
        {
            tmp[i]=j+10;
            BT(i+1);
        }
}

int main(){
    int rcnt,i;
    while(cin>>dicnt)
    {
        gets(dic[0]);
        for(i=0; i<dicnt; i++)
            gets(dic[i]);

        puts("--");
        cin>>rcnt;
        for(i=0;  i<rcnt; i++)
        {
            cin>>rule;
            BT(0);
        }
    }
}