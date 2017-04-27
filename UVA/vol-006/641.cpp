#include <stdio.h>
#include <cstring>

int lc[127];
char letters[] = "_abcdefghijklmnopqrstuvwxyz.";
int main(){
    for (int i=0; letters[i]; i++)
        lc[letters[i]] = i;

    int n, k;
    char s[100], o[100];
    while (scanf("%d %s", &k, s)==2 && k) {
        int n = strlen(s);
        for (int i=0; i<n; ++i)
            o[(k*i)%n] = letters[(lc[s[i]]+i)%28];
        o[n] = 0;
        puts(o);
    }
}
