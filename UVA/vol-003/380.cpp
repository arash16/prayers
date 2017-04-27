#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;


struct TimeDuration {
    int id, tm, du;
    TimeDuration(int id, int tm, int du): id(id), tm(tm), du(du) {}
};

list<TimeDuration> adj[10000];

bool used[10000];
list<int> usedNums;
void setUsed(int u) {
    if (!used[u]) {
        used[u] = 1;
        usedNums.push_back(u);
    }
}


bool inside[10000];
int forwardsTo(int u, int t) {
    if (inside[u]) return 9999;
    inside[u] = 1;
    for (TimeDuration tu: adj[u])
        if (t>=tu.tm && t<=tu.tm+tu.du) {
            int result = forwardsTo(tu.id, t);
            inside[u] = 0;
            return result;
        }

    inside[u] = 0;
    return u;
}




int main(){
    int T, u, v, tm, du;
    scanf("%d", &T);
    puts("CALL FORWARDING OUTPUT");
    for (int cse=1; cse<=T; cse++) {
        printf("SYSTEM %d\n", cse);
        for (int x: usedNums) {
            adj[x].clear();
            used[x] = 0;
        }

        while (scanf("%d", &u)==1 && u) {
            scanf("%d %d %d", &tm, &du, &v);
            adj[u].push_back(TimeDuration(v, tm, du));
            setUsed(u); setUsed(v);
        }

        while (scanf("%d", &tm)==1 && tm!=9000) {
            scanf("%d", &u);
            printf("AT %04d CALL TO %04d RINGS %04d\n", tm, u, forwardsTo(u, tm));
        }

    }
    puts("END OF OUTPUT");
}
