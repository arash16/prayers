/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 216
  Name: Getting in Line
  Problem: https://onlinejudge.org/external/2/216.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;

double x[8],y[8];
double dist(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

int used[8],n;
double best;
int ch[8];
int bch[8];
void BT(int i, double d)
{
    if(i==n)
    {
        if(d<best)
        {
            best=d;
            memcpy(bch,ch,sizeof(ch));
        }
    }
    else
        for(int j=0; j<n; j++)
            if(!used[j])
            {
                used[j]=1;
                ch[i]=j;
                BT( i+1 , i ? d+dist(ch[i-1],j) : 0 );
                used[j]=0;
            }
}

int main()
{
    int cse=1, i;

    while(cin>>n && n)
    {
        for(i=0; i<n; i++)
            cin>>x[i]>>y[i];

        best=10000000;
        BT(0, 0);
        puts("**********************************************************");
        printf("Network #%d\n",cse++);
        for(i=1; i<n; i++)
            printf("Cable requirement to connect (%.0lf,%.0lf) to (%.0lf,%.0lf) is %.2lf feet.\n",
                    x[bch[i-1]],y[bch[i-1]],x[bch[i]],y[bch[i]], dist(bch[i-1],bch[i])+16);

        printf("Number of feet of cable required is %.2lf.\n",best+16*(n-1));
    }
}