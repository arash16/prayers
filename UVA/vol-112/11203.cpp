#include <stdio.h>
#include <iostream>
using namespace std;


bool check(char word[]) {
    int i, a=0, b=0;

    for (i=0; word[i]=='?'; i++) a++;
    if (a <= 0 || word[i++]!='M') return 0;

    for (; word[i]=='?'; i++) b++;
    if (b <= 0 || word[i++]!='E') return 0;

    a += b;
    for (; word[i]=='?'; i++)
        if (--a < 0)
            return 0;

    return !a && !word[i];
}

int main(){
    int T;
    char word[100];
    scanf("%d", &T);
    while (T--) {
        scanf("%s", word);
        puts(check(word) ? "theorem" : "no-theorem");
    }
}
