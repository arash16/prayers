#include <stdio.h>
#include <iostream>
using namespace std;

int codes[127];
const char cgs[] = "AEIOUYWH|BPFV|CSKGJQXZ|DT|L|MN|R";
void print(const char s1[], const char s2[]) {
    printf("%9s%-25s%s\n", "", s1, s2);
}

int main(){
    int id=0;
    for (int i=0; cgs[i]; i++)
        if (cgs[i]=='|') id++;
        else codes[cgs[i]] = id;

    print("NAME", "SOUNDEX CODE");

    char w[30], c[5]; c[4]=0;
    while (cin>>w) {
        c[0]=w[0];

        int j=1;
        for (int i=1; j<4 && w[i]; i++)
            if (codes[w[i]] && codes[w[i]]!=codes[w[i-1]])
                c[j++] = '0'+codes[w[i]];

        for (; j<4; j++) c[j]='0';
        print(w, c);
    }
    printf("%19sEND OF OUTPUT\n", "");
}
