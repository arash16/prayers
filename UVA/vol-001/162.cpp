/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 162
  Name: Beggar My Neighbour
  Problem: https://onlinejudge.org/external/1/162.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;


int count(char num){
    if(num=='J' || !num)return 1;
    if(num=='Q')return 2;
    if(num=='K')return 3;
    if(num=='A')return 4;
    return 0;
}

int main(){
    int i;
    int pcs[2],tc,cp;
    bool finish;
    list<char>::iterator gi;
    char war,ch;
    char cardd[5];
    while(1){
        finish=0;
        list<char> deck[2],table;
        pcs[0]=pcs[1]=26;tc=0;
        for(i=1;i<=52;i++)
        {
            scanf("%s",cardd);
            if(cardd[0]=='#')return 0;
            deck[i%2].push_back(cardd[1]);
        }
        war=0;cp=1;

        while(!finish){
            if(war && !count(ch)){
                deck[cp].splice(deck[cp].begin(),table,table.begin(),table.end());
                pcs[cp]+=tc;
                tc=0;
                war=0;
            }
            for(i=1;i<=count(war);i++){
                if(!pcs[cp]){
                    finish=1;
                    break;
                }
                ch=deck[cp].back();
                deck[cp].pop_back();
                table.push_front(ch);
                pcs[cp]--;
                tc++;
                if(count(ch)){
                    war=ch;
                    break;
                }
            }
            cp=(cp+1)%2;
        }
        printf("%d%3d\n",cp+1,pcs[cp]);
    }
}