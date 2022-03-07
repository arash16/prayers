/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 410
  Name: Station Balance
  Problem: https://onlinejudge.org/external/4/410.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;

#define setbit(n,i) ((n)|(1<<(i)))
#define resetbit(n,i) ((n)&(~(1<<(i))))
#define isset(n,i) ((n)&(1<<(i)))

double am;
int sm[20],s;
double saved[2048][6];
int P[2048][6];

double rec(int set, int cnt){
    if(cnt==0)
        if(set==0)
            return 0;
        else
            return 10000000;

    if(saved[set][cnt]>=0)return saved[set][cnt];

    int i,j;
    double t,m=rec(set,cnt-1)+am;
    P[set][cnt]=0;

    for(i=0;i<s;i++)
        if(isset(set,i)){
            t=rec(resetbit(set,i),cnt-1)+fabs(am-sm[i]);
            if(t<m){
                m=t;
                P[set][cnt]=(1<<i);
            }

            for(j=i+1;j<s;j++)
                if(isset(set,j)){
                    t=rec(resetbit(resetbit(set,i),j),cnt-1)
                      +fabs(am-sm[i]-sm[j]);

                    if(t<m){
                        m=t;
                        P[set][cnt]=setbit(1<<i,j);
                    }
                }
        }
    return saved[set][cnt]=m;
}

int main(){
    int c,i,cse=0,set,cnt;
    double im;
    while(scanf("%d%d",&c,&s)==2){
        memset(saved,-1,sizeof(saved));
        am=0;
        for(i=0;i<s;i++){
            cin>>sm[i];
            am+=sm[i];
        }
        am/=c;

        im=rec((1<<s)-1,c);

        printf("Set #%d\n",++cse);
        set=(1<<s)-1;
        for(cnt=c; cnt>0; cnt--)
        {
            printf("%2d:",c-cnt);
            for(i=0;i<s;i++)
                if(isset(P[set][cnt],i))
                    cout<<" "<<sm[i];
            cout<<endl;
            set&=~P[set][cnt];
        }
        printf("IMBALANCE = %.5lf\n\n",im);
    }
}