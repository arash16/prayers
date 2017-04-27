/*
  >>> ACM PROBLEM <<<
  
  ID: 674
  Name: Coin Change
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


int coin[]={50,25,10,5,1};
int calc[7490][4]={0};

int recu(int c,int x){
    int i,k=0;
    if(x==4)return 1;
    else if(calc[c][x]!=0)return calc[c][x];
    else
    for(i=0;i<=(int)(c/coin[x]);i++)
      k+=recu(c-coin[x]*i,x+1);
    
    calc[c][x]=k;
    return k;
}

int main()
{
     int n,i,j;
     while (cin>>n)
           cout<<recu(n,0)<<endl;
  return 0;
}
