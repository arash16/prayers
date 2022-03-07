/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 11136
  Name: Hoax or what
  Problem: https://onlinejudge.org/external/111/11136.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <functional>
#include <queue>
using namespace std;


int main(){
    int n, m, x;
    while (scanf("%d", &n)==1 && n) {
        int elems = 0;
        priority_queue<int> qmx;
        priority_queue<int, vector<int>, greater<int> > qmn;


        long long sum = 0;
        for (int i=0; i<n; ++i) {
            scanf("%d", &m);
            elems += m - 2;

            for (int i=0; i<m; i++) {
                scanf("%d", &x);
                qmx.push(x);
                qmn.push(x);
            }

            sum += qmx.top() - qmn.top();
            if (elems) {
                qmx.pop();
                qmn.pop();
            }
            else {
                qmx = priority_queue<int>();
                qmn = priority_queue<int, vector<int>, greater<int> >();
            }
        }

        printf("%lld\n", sum);
    }
}
