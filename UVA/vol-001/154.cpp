/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 154
  Name: Recycling
  Problem: https://onlinejudge.org/external/1/154.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int code(char c)
{
    switch(c)
    {
        case 'r':return 0;
        case 'o':return 1;
        case 'y':return 2;
        case 'g':return 3;
        case 'b':return 4;
    }
}

char b[101][5];
int city;


int diff(int i, int j)
{
    int cnt=0;
    for(int k=0; k<5; k++)
        cnt += (b[i][k] != b[j][k]);

    return cnt;
}

int solve()
{
    int i,j,t=0,tdiff,md;
    md=100000;
    for(i=0; i<city; i++)
    {
        tdiff=0;
        for(j=0; j<city; j++)
            if(i!=j)
                tdiff += diff(i,j);

        if(tdiff<md)
        {
            t=i;
            md=tdiff;
        }
    }
    return t;
}


int main(){
    int i;
    char s[1000];
    while(1){
        gets(s);

        if(s[0]=='#')return 0;

        else if(s[0]=='e')
        {
            cout<<solve()+1<<endl;
            city=0;
        }

        else
        {
            for(i=0; i<20; i+=4)
                b[city][code(s[i])]=toupper( s[i+2] );

            city++;
        }
    }
}