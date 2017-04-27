#include <stdio.h>
#include <iostream>
using namespace std;

#define MaxInt 2147483647

int T,R,H;
int cT[20],cR[20],cH[20];
bool mT[20][20], mR[20][20], mH[20][20];

int main()
{
    int i,j,k;
    int chT,chR,chH;
    int bT,bR,bH,m;

    while(cin>>T>>R>>H)
    {
        for(i=0; i<T; i++)
        {
            cin>>cT[i];
            for(j=0; j<R; j++)
                cin>>mT[i][j];
        }
        for(i=0; i<R; i++)
        {
            cin>>cR[i];
            for(j=0; j<H; j++)
                cin>>mR[i][j];
        }
        for(i=0; i<H; i++)
        {
            cin>>cH[i];
            for(j=0; j<T; j++)
                cin>>mH[i][j];
        }

        m=MaxInt;
        for(k=0; k<T*R*H; k++)
        {
            chT=k%T;
            chR=(k/T)%R;
            chH=((k/T)/R)%H;

            if(!mT[chT][chR] && !mR[chR][chH] && !mH[chH][chT])
                if(cT[chT]+cR[chR]+cH[chH] < m)
                {
                    bT=chT;  bR=chR;  bH=chH;
                    m=cT[chT]+cR[chR]+cH[chH];
                }
        }

        if( m==MaxInt )
            puts("Don't get married!");
        else
            printf("%d %d %d:%d\n",bT,bR,bH,m);
    }
}