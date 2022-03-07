/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10050
  Name: Hartals
  Problem: https://onlinejudge.org/external/100/10050.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
using namespace std;


int main()
{
  bool days[3651];
  int t,k,n,p,i,j,count;

  cin>>t;
  while(t--){
    int n;
    cin>>n;
    for(i=1;i<=n;i++)days[i]=0;

    int p;
    cin>>p;
    for(i=0;i<p;i++){
      cin>>k;
      for(j=k;j<=n;j+=k)days[j]=true;
    }
    count=0;
    for(i=1;i<=n;i++)if(i%7==6)i++;else if(days[i])count++;

    cout<<count<<endl;
  }
  return 0;
}
