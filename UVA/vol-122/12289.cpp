#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;


int diff(char *w1, char *w2) {
    int r=0;
    for(int i=0; i<3; i++)
        if (w1[i] != w2[i])
            r++;
    return r;
}

int main() {
    int n;
    cin>>n;
    while(n--) {
        char word[10];
        cin>>word;
        if (strlen(word)==5)
            cout<<"3\n";
        else if (diff(word, "one") < diff(word, "two"))
            cout<<"1\n";
        else
            cout<<"2\n";
    }
}
