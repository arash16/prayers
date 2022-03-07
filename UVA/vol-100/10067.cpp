/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 10067
  Name: Playing with Wheels
  Problem: https://onlinejudge.org/external/100/10067.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int readNum(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    return a*1000+b*100+c*10+d;
}

int rot(int num, int w) {
    int sgn = w<0?-1:1;
    w = w<0?-w-1:w-1;
    int t=1;
    for (int i=0; i<w; i++) t*=10;
    int r = (10 + ((num/t)%10 + sgn))%10;
    return (10*(num/(10*t))+r)*t + num%t;
}

int d[10000];

int main(){
    int T, n;
    cin>>T;
    while (T--) {
        memset(d, 0, sizeof(d));
        int s = readNum(),
            t = readNum();

        cin>>n;
        for (int i=0; i<n; i++) {
            int tt = readNum();
            if (tt != s && tt!=t)
                d[tt] = -1;
        }

        int result = -1;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int num = q.front(); q.pop();
            int dd = d[num];
            if (num == t) { result = dd; break; }
            if (dd < 0) continue;
            d[num] = -1;

            for (int i=-4; i<=4; i++) if(i) {
                int nn = rot(num, i);
                if (!d[nn]) {
                    q.push(nn);
                    d[nn] = dd+1;
                }
            }
        }

        cout << result << endl;
    }
}
