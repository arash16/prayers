#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;


inline int bound(int n,int t){
    return ceil(log((float)n/t)/0.693147); //  [log2(n/t)]
}


int n,ans[10001],best;
int A[10001]={1,0};
void AdditionChain(int i)
{
    int k,j;

    for(j=i-1;j>=0;j--)
        for(k=j;k>=0;k--)
            if(A[k]+A[j]<=n && A[k]+A[j]>A[i-1])
                if(i+bound(n,A[i-1])<best)
                {
                    A[i]=A[k]+A[j];
                    if(A[i]==n)
                    {
                        best=i+1;
                        for(int j=0;j<best;j++)
                            ans[j]=A[j];
                    }
                    else
                        AdditionChain(i+1);
                }
}

int main()
{
    int i;

    while(scanf("%d",&n)==1 && n>0)
    {
        best=1000;
        if(n==1)
            best=1;
        else
            AdditionChain(1);

        cout<<1;
        for(i=1;i<best;i++)
            cout<<' '<<ans[i];
        cout<<endl;
    }
}