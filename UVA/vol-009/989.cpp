#include <stdio.h>
#include <iostream>
using namespace std;

int n,a[10][10];
bool check(int i,int j,int x)
{
    int k,l;
    for(k=0; k<n*n; k++)
        if((k!=i && a[k][j]==x)||(k!=j && a[i][k]==x))
            return false;

    for(k=(i/n)*n ; k<(i/n)*n+n ; k++)
        for(l=(j/n)*n ; l<(j/n)*n+n; l++)
            if((k!=i || l!=j) && a[k][l]==x)
                return false;

    return true;
}

bool BT(int cell){
    if(cell==n*n*n*n)
        return true;

    int i=cell/(n*n);
    int j=cell%(n*n);

    if(a[i][j])
        return BT(cell+1);

    for(int x=1; x<=n*n; x++)
        if(check(i,j,x))
        {
            a[i][j]=x;
            if( BT(cell+1) )
                return true;
        }

    a[i][j]=0;
    return false;
}

int main(){
    int i,j,cse=0;
    while(scanf("%d",&n)==1)
    {
        if(cse++)cout<<endl;

        for(i=0; i<n*n; i++)
            for(j=0; j<n*n; j++)
                cin>>a[i][j];

        if(BT(0))
            for(i=0; i<n*n; i++)
            {
                cout<<a[i][0];
                for(j=1; j<n*n; j++)
                    cout<<" "<<a[i][j];
                cout<<endl;
            }
        else
            puts("NO SOLUTION");
    }
}