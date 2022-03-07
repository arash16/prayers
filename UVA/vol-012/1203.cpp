/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1203
  Name: Argus
  Problem: https://onlinejudge.org/external/12/1203.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct Event {
    int qid, tm;
    Event(int q, int t):qid(q),tm(t){}
    bool operator < (const Event &e) const {
        return tm==e.tm ? qid>e.qid : tm>e.tm;
    }
};

int qs[10000];

int main(){
    int qid, t, n;
    priority_queue<Event> q;
    while (scanf("Register %d %d\n", &qid, &t)==2) {
        q.push(Event(qid, t));
        qs[qid] = t;
    }

    scanf("%*s%d", &n);
    for (int i=0; i<n; i++) {
        int tqid = q.top().qid;
        printf("%d\n", tqid);
        q.push(Event(tqid, q.top().tm+qs[tqid]));
        q.pop();
    }
}
