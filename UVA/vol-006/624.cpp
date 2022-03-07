/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 624
  Name: CD
  Problem: https://onlinejudge.org/external/6/624.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

int du[21],c,best;
int tmp[21],ans[21];
void BT(int i, int n){
    if(i==c)
    {
        if(n<best)
        {
            best=n;
            memcpy(ans,tmp,sizeof(tmp));
        }
        return;
    }

    if(n-du[i]>=0)
    {
        tmp[i]=1;
        BT(i+1,n-du[i]);
    }
    tmp[i]=0;
    BT(i+1,n);
}

int main(){
    int N;
    while(cin>>N){
        cin>>c;
        for(int i=0; i<c; i++)
            cin>>du[i];

        best=2147483647;
        BT(0,N);
        for(int i=0; i<c; i++)
            if(ans[i])
                cout<<du[i]<<' ';
        cout<<"sum:"<<N-best<<endl;
    }
}