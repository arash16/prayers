#define INF 1073741824
#include <stdio.h>
#include <iostream>
using namespace std;

int cse, coins[101],
    memoid[101][10001], memo[101][10001];
int opt(int ind, int rem) {
    if (!ind || rem<=0)
        return rem>0 ? INF : -rem*1000;
    if (memoid[ind][rem] == cse)
        return memo[ind][rem];

    int best = INF;
    for (int i=0; i<ind; i++)
        best = min(best, opt(i, rem-coins[i]) + 1);

    memoid[ind][rem] = cse;
    return memo[ind][rem] = best;
}

int main(){
    int T, n, price;
    scanf("%d", &T);
    for (cse=1; cse<=T; cse++) {
        scanf("%d%d", &price, &n);
        for (int i=0; i<n; i++)
            scanf("%d", coins+i);

        int result = opt(n, price);
        printf("%d %d\n", price + result/1000, result%1000);
    }
}
