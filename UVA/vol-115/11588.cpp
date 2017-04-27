#include <stdio.h>

void skipline() { while(getchar()!='\n'); }
char A[500];
int main() {
    int T, cse=1, n, m, x, y;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &n, &m, &x, &y);
        int freq[26]={}, mx=0;
        for (int i=0; i<n; ++i) {
            skipline();
            for (int j=0; j<m; ++j) {
                char ch = A[i*m + j] = getchar()-'A';
                if (++freq[ch] > mx)
                    mx = freq[ch];
            }
        }

        int sum = 0;
        for (int i=0; i<n*m; ++i)
            sum += freq[A[i]] == mx ? x : y;

        printf("Case %d: %d\n", cse++, sum);
    }
}
