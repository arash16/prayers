/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 523
  Name: Minimum Transport Cost
  Problem: https://onlinejudge.org/external/5/523.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;
int w[1000][1000];
int v[100];
int mid[1000][1000];

int main(){
    int M;
    int i,j,t,n;
    int src,dest;
    char *p,line[1000];

    scanf("%d\n",&M);
    while(M--){
        gets(line);
        for(n=1,p=strtok(line," ");p;p=strtok(0," "),n++){
            sscanf(p,"%d",&w[1][n]);
            if(w[1][n]==-1)w[1][n]=100000;
            mid[1][n]=n;
        }n--;

        for(i=2;i<=n;i++)
            for(j=1;j<=n;j++){
                scanf("%d",&w[i][j]);
                if(w[i][j]==-1)w[i][j]=100000;
                mid[i][j]=j;
            }

        for(i=1;i<=n;i++)
            scanf("%d",&v[i]);

        for(t=1;t<=n;t++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    if(w[i][t]+w[t][j]+v[t]<w[i][j]){
                        w[i][j]=w[i][t]+w[t][j]+v[t];
                        mid[i][j]=mid[i][t];
                    }

        gets(line);
        while(gets(line) && strlen(line)>1)
        {
            sscanf(line,"%d%d",&src,&dest);
            printf("From %d to %d :\nPath: ",src,dest);
            for(i=src;i!=dest;i=mid[i][dest])
                cout<<i<<"-->";
            cout<<dest<<endl;
            printf("Total cost : %d\n",w[src][dest]);
        }
        if(M)printf("\n");
    }
}