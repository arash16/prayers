/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 555
  Name: Bridge Hands
  Problem: https://onlinejudge.org/external/5/555.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <set>

using namespace std;

char tt[]="CDSH23456789TJQKA";
char swne[]="SWNE";
class card{
public:
    char suit;
    char num;
    bool operator<(const card &t) const{
        char *p1,*p2,*p3,*p4;
        p1=strchr(tt,suit); p2=strchr(tt,t.suit);
        p3=strchr(tt,num);  p4=strchr(tt,t.num);
        if(p1<p2)return 1;
        else if(p1==p2 && p3<p4)return 1;
        else return 0;
    }
};

int main(){
    char start;
    int nt,pi,i;
    set<class card> players[4];
    set<class card>::iterator j;
    class card pt;
    while((start=getchar())!='#'){
        getchar();
        for(pi=0;swne[pi]!=start;pi++);
        for(i=1;i<=52;i++){
            if(i==27)getchar();
            pt.suit=getchar();
            pt.num=getchar();
            players[(i+pi)%4].insert(pt);
        }
        for(i=0;i<4;i++){
            printf("%c:",swne[i]);
            for(j=players[i].begin();j!=players[i].end();j++)
                printf(" %c%c",j->suit,j->num);
            printf("\n");
            players[i].clear();
        }
        getchar();
    }
    return 0;
}