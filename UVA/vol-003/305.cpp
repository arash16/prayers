/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 305
  Name: Joseph
  Problem: https://onlinejudge.org/external/3/305.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
using namespace std;

int main(){
     int n,answer[]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};
     while(cin>>n && n)
       cout<<answer[n]<<endl;
     return 0;
}
/*
int main()
{
     int i,j,n,t,t2,ans,e=1;;
     while (cin>>n && n)
     {
           for(i=n+1;e;i++)
           {
             //if(!(n%i))i+=n;3,5
             t=2*n;//6
             t2=(i-1)%t-1;t--;
             e=0;
             for(j=0;j<n;j++)
               if(t2<n-1){e=1;break;}else{
                  t2=(t2+i)%t-1;
                  t--;
               }
             ans=i;
           }
           e=1;
           printf("%d\n",ans);

     }
  return 0;
}
*/
