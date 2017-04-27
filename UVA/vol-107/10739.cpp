#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;

char s[1001];
int DP[1001][1001];
int main(){
    int T,cse=1,l,i,j;
    cin>>T;
    while(T--){
        cin>>s;
        l=strlen(s);
        for(i=l-1;i>=0;i--)
            for(j=i+1;j<l;j++)
                if(s[i]==s[j])
                    DP[i][j]=DP[i+1][j-1];
                else
                    DP[i][j]=1+min(min(DP[i+1][j],DP[i][j-1]),DP[i+1][j-1]);

        printf("Case %d: %d\n",cse++,DP[0][l-1]);
    }
}