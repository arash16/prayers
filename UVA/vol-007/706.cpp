/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 706
  Name: LC-Display
  Problem: https://onlinejudge.org/external/7/706.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
#include <cstring>
using namespace std;

void coutX(char ch,int x){
     while(x--)cout<<ch;
}

int main()
{
   bool lcd[10][7]={{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},
                    {1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
   int s,i,j,k,len,nt,st;
   char num[12];

   while (scanf("%d%s",&s,num)!=-1 && s)
   {
      len=strlen(num);
      st=0;
      for(i=0;i<7;i++)
        if(i==1 || i==4){
           for(j=0;j<s;j++)
           {
              for(k=st;k<len;k++){
                 nt=num[k]-'0';
                 if(nt>9 || nt<0)continue;
                 cout<<(lcd[nt][i]?"|":" ");
                 coutX(' ',s);
                 cout<<((lcd[nt][i+1])?"|":" ");
                 if(k<len-1)cout<<" ";
              }
              cout<<endl;
           }
        }else if(i%3==0){
           for(k=st;k<len;k++){
             nt=num[k]-'0';
             if(nt>9 || nt<0)continue;
             cout<<" ";
             coutX(lcd[nt][i]?'-':' ',s);
             cout<<" ";
             if(k<len-1)cout<<" ";
           }
           cout<<endl;
        }
        cout<<endl;
   }
  return 0;
}
