#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define MAXL 100000

int wcnt=0, ccnt=0;
char line[MAXL], carry[MAXL];
string words[1000];

void addWord() {
    if (ccnt > 0) {
        carry[ccnt] = 0;
        words[wcnt++] = carry;
        ccnt = 0;
    }
}

int main() {
    int i;
    while (cin.getline(line, MAXL)) {
        for (i=0; line[i]; ++i) {
            if (isalpha(line[i]) || (line[i]=='-' && line[i+1]))
                carry[ccnt++] = tolower(line[i]);

            else if (line[i]!='-')
                addWord();
        }
        if (i>0 && line[i-1]!='-')
            addWord();
    }
    if (ccnt) addWord();

    sort(words, words+wcnt);
    cout << words[0] << endl;
    for (int i=1; i<wcnt; ++i)
        if (words[i] != words[i-1])
            cout << words[i] << endl;
}

