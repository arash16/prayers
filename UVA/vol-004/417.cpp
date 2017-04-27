#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> encodes;

int cur;
char curw[10];
void rec(int l, int ind) {
    if (ind == l) encodes[curw] = ++cur;
    else {
        char last = ind==0 ? 'a'-1 : curw[ind-1];
        for (char ch=last+1; ch<='z'; ch++) {
            curw[ind] = ch;
            rec(l, ind+1);
        }
    }
}

int main(){
    for (int i=1; i<=5; i++) {
        curw[i] = 0;
        rec(i, 0);
    }


    char word[20];
    while(cin>>word)
        cout << encodes[word] << endl;
}
