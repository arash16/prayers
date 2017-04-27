#include <stdio.h>

int main() {
    char s[1000], d;
    while (scanf(" %c %s", &d, s)==2 && d!='0') {
        int j=0;
        for (int i=0; s[i]; i++)
            if (s[i] != d)
                s[j++] = s[i];
        s[j] = 0;

        int i=0;
        while (s[i] == '0') ++i;
        if (i < j) puts(s+i);
        else puts("0");
    }
}
