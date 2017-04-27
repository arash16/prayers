#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    int n, sum, id, x;
    while (cin>>n) {
        bool ip=1, iq=1, is=1;
        priority_queue<int> p;
        queue<int> q;
        stack<int> s;
        sum=3;

        for (int i=0; i<n; i++) {
            cin >> id >> x;

            if (sum) {
                if (id == 1) {
                    if (ip) p.push(x);
                    if (iq) q.push(x);
                    if (is) s.push(x);
                }
                else {
                    if (ip) {
                        if (p.empty()) ip=0;
                        else {
                            if (x != p.top()) ip=0;
                            p.pop();
                        }
                    }
                    if (iq) {
                        if (q.empty()) iq=0;
                        else {
                            if (x != q.front()) iq=0;
                            q.pop();
                        }
                    }
                    if (is) {
                        if (s.empty()) is=0;
                        else {
                            if (x != s.top()) is=0;
                            s.pop();
                        }
                    }
                }
                sum = ip+iq+is;
            }
        }

        if (!sum) puts("impossible");
        else if (sum>1) puts("not sure");
        else if (ip) puts("priority queue");
        else if (iq) puts("queue");
        else puts("stack");
    }
}
