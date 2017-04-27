/*
  >>> ACM PROBLEM <<<

  ID: 294
  Name: Divisors
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
*/
#define maxp 32000
#include <iostream>
#include <cstring>
#include <cmath>
#include <list>
#include <map>

using namespace std;



list<int> primes;
bool pt[maxp];
void calcprimes(){
     int i,j;
     for(i=2;i<maxp;i++)pt[i]=1;
     for(i=2;i<sqrt(maxp)+3;i++)
       if(pt[i]){
          primes.push_back(i);
          for(j=i;j<maxp;j+=i)
            pt[j]=0;
       }
     for(;i<maxp;i++)
       if(pt[i])primes.push_back(i);
}

int count(unsigned long int x){
    list<int>::iterator i;
    int c=1,t;
    unsigned long int y=x;

    for(i=primes.begin();i!=primes.end() && (*i)<sqrt(y)+1;i++){
        t=0;
        while(x%(*i)==0){
          t++;x/=(*i);
        }
        c*=(t+1);
    }
    if(x!=1)c*=2;
    return c;
}

int main()
{
     int n,t,max;
     unsigned long int i,l,u,m;

     calcprimes();

     cin>>n;
     while (n--)
     {
           scanf("%lu%lu",&l,&u);
           max=0;
           for(i=l;i<=u;i++)
             if((t=count(i))>max)max=t,m=i;

           printf("Between %lu and %lu, %lu has a maximum of %d divisors.\n",l,u,m,max);
     }
  return 0;
}
