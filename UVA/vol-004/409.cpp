/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 409
  Name: Excuses, Excuses!
  Problem: https://onlinejudge.org/external/4/409.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;

const char tokens[] = " \t\"'.,:;~`!?@#$%^&*()<>/\\0123456789";
char tolower(char c) {
    if (c>='A' && c<='Z')
        return c-'A'+'a';
    return c;
}

int main(){
    int cse=1, n, m, scores[30];
    char lines[30][100], word[100];

    while (cin>>n>>m) {
        map<string, int> key;

        for (int i=0; i<n; i++) {
            cin>>word;
            key[word] = 1;
        }
        cin.getline(word, 100);

        int j, maxscore = -1;
        for (int i=0; i<m; i++) {
            cin.getline(lines[i], 100);

            for (j=0; lines[i][j]; j++)
                word[j] = tolower(lines[i][j]);
            word[j]=0;

            scores[i] = 0;
            for (char *p=strtok(word, tokens); p; p=strtok(0, tokens))
                scores[i] += key[p];

            if (scores[i]>maxscore)
                maxscore = scores[i];
        }

        printf("Excuse Set #%d\n", cse++);
        for (int i=0; i<m; i++)
            if (scores[i] == maxscore)
                puts(lines[i]);

        putchar('\n');
    }
}
