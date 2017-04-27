#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, n;
    char s[3000];
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n, s);
        int r = 0;
        for (int i=0; s[i]; i++)
            r = (r*10 + s[i] - '0') % n;

        printf("%d\n", r);
    }
}
