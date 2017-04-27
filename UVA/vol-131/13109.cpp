#include <stdio.h>
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main(){
    int T, n, m, w, c;
    scanf("%d", &T);
    while (T--) {
        priority_queue<int, vector<int>, greater<int> > q;
        scanf("%d%d", &n, &m);

        for (int i=0; i<n; i++) {
            scanf("%d", &w);
            q.push(w);
        }

        for (c=0; !q.empty(); q.pop()) {
            m -= q.top();
            if (m >= 0) c++;
            else break;
        }

        printf("%d\n", c);
    }
}
