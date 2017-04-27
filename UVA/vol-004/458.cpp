#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char ch;
    while((ch=getchar())!=EOF)
        if (ch=='\n') cout<<endl;
        else cout<<char(ch-7);
}
