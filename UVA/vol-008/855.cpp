#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int T, n, X[50001], Y[50001];
    scanf("%d", &T);
    while (T--) {
        scanf("%*d%*d%d", &n);
        for (int i=0; i<n; ++i)
            scanf("%d%d", X+i, Y+i);

        int mid = (n-1)>>1;
        nth_element(X, X+mid, X+n);
        nth_element(Y, Y+mid, Y+n);

        printf("(Street: %d, Avenue: %d)\n", X[mid], Y[mid]);
    }
}
