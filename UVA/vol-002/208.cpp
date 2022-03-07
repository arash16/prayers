/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 208
  Name: Firetruck
  Problem: https://onlinejudge.org/external/2/208.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int map[21][21], m[21][21] ,d, mx;
int used[21], p[21];

int BT(int i)
{
    if(p[i-1]==d-1)
    {
        for(int k=0; k<i-1; k++)
            cout<<p[k]+1<<" ";
        cout<<d<<endl;
        return 1;
    }

    else

    {
        int cnt=0;
        for(int k=1; k<mx; k++)
            if(!used[k] && map[p[i-1]][k] && m[k][d-1])
            {
                used[k]=1;
                p[i]=k;
                cnt+=BT(i+1);
                used[k]=0;
            }
        return cnt;
    }
}


int main()
{
    int i,j,k,cse=1;
    while(cin>>d)
    {
        memset(map,0,sizeof(map));
        memset(m,0,sizeof(m));
        mx=0;
        while(cin>>i>>j && (i||j))
        {
            map[i-1][j-1]=map[j-1][i-1]=1;
            m[i-1][j-1]=m[j-1][i-1]=1;
            mx=max(mx, max(i,j));
        }

        for(k=0; k<mx; k++)
            for(i=0; i<mx; i++)
                for(j=0; j<mx; j++)
                    if(m[i][k] && m[k][j])
                        m[i][j]=1;

        printf("CASE %d:\n",cse++);
        printf("There are %d routes from the firestation to streetcorner %d.\n",BT(1),d);
    }
}