#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

char lines[] = "`1234567890-=\tqwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
char m[256];
int main(){
    for(int i=1; lines[i]; i++)
        m[lines[i]]=toupper(lines[i-1]);

    char ch;
    while((ch=getchar())!=EOF)
        if (m[ch]) cout<<m[ch];
        else cout<<ch;
}
