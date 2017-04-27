/*
  >>> ACM PROBLEM <<<
  
  ID: 10258
  Name: Contest Scoreboard
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C++
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define ms(a,n) memset(a,n,sizeof(a))
struct person{
       int id;
       int count;
       int penalty[10];
};

int main()
{
  int tt;cin>>tt;
  char line[100],l;
  int m,prob,time,i,j;

  
  gets(line);gets(line);
  while(tt--){
    vector<person> membs(110);
    bool probs[110][15]={{0}};

    while(gets(line) && sscanf(line,"%d %d %d %c",&m,&prob,&time,&l)==4)
    {
       if(prob<1 || m<1)continue;
       membs[m].id=m;

       if(l=='C' && !probs[m][prob])
       {
         membs[m].count++;
         membs[m].penalty[prob]+=time;
         probs[m][prob]=1;
       } else if(l=='I' && !probs[m][prob])
         membs[m].penalty[prob]+=20;
    }
    
    for(i=1;i<101;i++){
      time=0;
      for(j=1;j<10;j++)
         if(probs[membs[i].id][j])time+=membs[i].penalty[j];
      membs[i].penalty[0]=time;
    }
    
    for(i=1;i<101;i++)
      for(j=1;j<101;j++)
        if(membs[i].count>membs[j].count)swap(membs[i],membs[j]);
        else if(membs[i].count==membs[j].count)
          if(membs[i].penalty[0]<membs[j].penalty[0])swap(membs[i],membs[j]);
          else if(membs[i].penalty[0]==membs[j].penalty[0])
            if(membs[i].id<membs[j].id)swap(membs[i],membs[j]);

    for(i=1;i<101;i++)
      if(membs[i].id)cout<<membs[i].id<<" "<<membs[i].count<<" "<<membs[i].penalty[0]<<endl;
    if(tt)cout<<endl;
        
  }
  return 0;
}
