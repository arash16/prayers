/*
  >>> ACM PROBLEM <<<
  
  ID: 568
  Name: Just the Facts
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
*/

#include <iostream>
#include <cstring>
using namespace std;

int count5(int x){
    int xp=5,c=0,t;
    while((t=x/xp)>=1){
      c+=t;
      xp*=5;
    }
    return c;
}

int main()
{
     int n,c5,c2,t,mult;     
     while (cin>>n)
     {
         mult=1;
         c5=count5(n);
         c2=c5;
         for(int i=2;i<=n;i++){
            t=i;
            while(c5 && !(t%5))t/=5,c5--;
            while(c2 && !(t%2))t/=2,c2--;
            mult*=(t%10);mult%=10;
         }
         printf("%5d -> %d\n",n,mult);
     }
  return 0;
}
