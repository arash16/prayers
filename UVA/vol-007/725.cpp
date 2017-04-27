#include <stdio.h>
#include <iostream>
using namespace std;

int N;
int used[11],cnt;
int x[3628801];
int y[3628801];
void BT(int i ,long long int p)
{
    if(i==10)
    {
        int a=p/100000;
        int b=p%100000;
        x[cnt]=a;
        y[cnt++]=b;
        return;
    }

    for(int j=0; j<10; j++)
        if(!used[j])
        {
            used[j]=1;
            BT(i+1,p*10+j);
            used[j]=0;
        }
}


int main()
{
    int cse=0,t;
    cnt=0;
    BT(0,0);
    while(cin>>N && N)
    {
        t=0;
        if(cse++)
            cout<<endl;

        for(int i=0; i<cnt; i++)
            if(y[i] && x[i]/y[i]==N && x[i]%y[i]==0)
                printf("%05d / %05d = %d\n",x[i],y[i],N),t=1;

        if(!t)
            printf("There are no solutions for %d.\n",N);
    }
}