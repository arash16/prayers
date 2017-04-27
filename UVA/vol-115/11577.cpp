#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
    char line[400];
    int freq[26];
    int T;
    cin>>T;
    cin.getline(line, 400);
    while (T--) {
        memset(freq, 0, sizeof(freq));
        cin.getline(line, 400);

        int mx=0;
        for (int i=0; line[i]; i++) {
            char ch = tolower(line[i]);
            if (ch>='a' && ch<='z') {
                int t = ++freq[ch-'a'];
                if (t > mx) mx = t;
            }
        }

        for (int i=0; i<26; i++)
            if (freq[i] == mx)
                putchar('a' + i);
        putchar('\n');
    }
}
