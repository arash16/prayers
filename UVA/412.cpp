/*
  >>> ACM PROBLEM <<<
  
  ID: 412
  Name: Pi
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
*/

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int gcd(int x,int y){
    int c,a=x,b=y;
    if(a<b){a+=b;b=a-b;a-=b;}
    while(1){
      c=a%b;
      if(!c)break;
      a=b;
      b=c;
    }
    return b;
}

int main()
{
   int n,a[50],sum,i,j,k;
   double t;
   while (cin>>n && n)
   {
      for(i=0;i<n;i++)
        cin>>a[i];
      sum=0;
      t=n*(n-1)/2;
      for(i=0;i<n;i++)
        for(j=i+1;j<n;j++){
          if(a[i]==a[j])t--;
          if(gcd(a[i],a[j])==1)sum++;
        }
      t=3*n*(n-1);t/=sum;
      if(sum)printf("%.6f\n",sqrt(t));
      else cout<<"No estimate for this data set.\n";
   }
   return 0;
}
