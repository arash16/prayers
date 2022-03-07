/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 489
  Name: Hangman Judge
  Problem: https://onlinejudge.org/external/4/489.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
    int r;
    bool word[128];
    bool gues[128];
    char ch;

    memset(word, -1, sizeof(word));
    while(cin>>r && r!=-1) {
        cout << "Round " << r << endl;
        while (getchar()!='\n');

        int d = 0;
        for (int i='a'; i<='z'; i++) word[i]=gues[i]=0;
        while ((ch=getchar()) != '\n')
            if (!word[ch]) {
                word[ch] = true;
                d++;
            }

        int wa=0, res=-1;
        while ((ch=getchar()) != '\n')
            if (res<0 && !gues[ch]) {
                gues[ch] = true;
                if (!word[ch]) wa++;
                else d--;

                res = 0;
                if (d==0) cout<<"You win.\n";
                else if (wa==7) cout<<"You lose.\n";
                else res=-1;
            }

        if (res==-1) cout<<"You chickened out.\n";
    }
}
