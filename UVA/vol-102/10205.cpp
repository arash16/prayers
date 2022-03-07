/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10205
  Name: Stack 'em Up
  Problem: https://onlinejudge.org/external/102/10205.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

char suits[][9]={"Clubs","Diamonds","Hearts","Spades"};
char nums[][6]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};

string name(int x){

}

int main()
{
  int T;cin>>T;
  int n,i,j,ay,s,f=0;
  int shuffle[100][52];
  char line[10];
  vector<int> cards,tc;
  for(i=1;i<53;i++)tc.push_back(i);


  while(T--){
    if(f)cout<<endl;f=1;
    cin>>n;
    for(i=0;i<n;i++)
      for(j=0;j<52;j++)
        cin>>shuffle[i][j];
    cards.clear();
    for(i=1;i<53;i++)cards.push_back(i);

    gets(line);
    while(gets(line) && strlen(line)){
      sscanf(line,"%d",&s);
      for(i=0;i<52;i++)
        tc[i]=cards[shuffle[s-1][i]-1];
      cards=tc;
    }
    for(i=0;i<52;i++)
      printf("%s of %s\n",nums[(cards[i]-1)%13],suits[(int)(cards[i]-1)/13]);
  }

  return 0;
}
