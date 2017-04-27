#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int tt;cin>>tt;
    int m,n,k,i,j,u,bits,len;
    char mat[1000][1000],word[1000],t;
    while(tt--){
      cin>>m>>n;cin.ignore(1);
      for(i=0;i<m;i++){
        for(j=0;j<n;j++){
          cin>>t;
          if(isalpha(t))mat[i][j]=tolower(t);
        }
        cin.ignore(1);
      }
      cin>>k;cin.ignore(1);

      while(k--){
        cin>>word;
        len=strlen(word);
        for(i=0;i<len;i++)word[i]=tolower(word[i]);
        for(i=0;i<m;i++)
          for(j=0;j<n;j++){
            bits=63;
            for(u=0;u<len && bits;u++){
              if(j+u>=n || mat[i][j+u]!=word[u])bits&=62;
              if(i+u>=m || mat[i+u][j]!=word[u])bits&=61;
              if(i+u>=m || j+u>=n || mat[i+u][j+u]!=word[u])bits&=59;

              if(j-u<0 || mat[i][j-u]!=word[u])bits&=55;
              if(i-u<0 || mat[i-u][j]!=word[u])bits&=47;
              if(i-u<0 || j-u<0 || mat[i-u][j-u]!=word[u])bits&=31;
            }
            if(u==len && bits){printf("%d %d\n",i+1,j+1);goto br;}
          }
        br:;
      }
      if(tt)cout<<endl;
    }
    return 0;
}
