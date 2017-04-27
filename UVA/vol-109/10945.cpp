#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

char line[1000000];
char toUpper(char ch) {
    if (ch>='a') return ch - 'a' + 'A';
    return ch;
}


bool check(int l) {
    for (int i=l/2; i>=0; i--)
        if (toUpper(line[i]) != toUpper(line[l-i-1]))
            return false;

    return true;
}

int main(){
    char ch;
    while (true) {
        int i = 0;
        bool o = false;
        while ((ch=getchar()) != '\n')
            if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
                line[i++] = ch;
            else o = true;

        line[i] = 0;
        if ((!o && strcmp(line, "DONE")==0)) return 0;

        if (check(i)) cout << "You won't be eaten!\n";
        else cout << "Uh oh..\n";
    }
}

