#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

char sold[100001];
int main(){
    int T, n, m, k, x;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &k, &n, &m);
        priority_queue<int> qb, qg;
        for (int i=0; i<n; ++i) {
            scanf("%d", &x);
            qg.push(x);
        }
        for (int i=0; i<m; ++i) {
            scanf("%d", &x);
            qb.push(x);
        }

        while (qg.size() && qb.size()) {
            int c = min(k, (int)min(qb.size(), qg.size()));
            for (int i=0; i<c; ++i) {
                sold[i] = qg.top() - qb.top();
                qg.pop(); qb.pop();
            }

            for (int i=0; i<c; ++i)
                if (sold[i])
                    if (sold[i] > 0)
                         qg.push(+sold[i]);
                    else qb.push(-sold[i]);
        }

        if (!qg.empty()) {
            puts("green wins");
            for(; !qg.empty(); qg.pop())
                printf("%d\n", qg.top());
        }

        else if (!qb.empty()) {
            puts("blue wins");
            for(; !qb.empty(); qb.pop())
                printf("%d\n", qb.top());
        }

        else puts("green and blue died");
        if (T) putchar('\n');
    }
}
