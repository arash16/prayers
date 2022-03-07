/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 1585
  Name: Score
  Problem: https://onlinejudge.org/external/15/1585.pdf
  Language: C++

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char word[100];
    int n;
    cin>>n;
    while(n--) {
        cin>>word;
        int sum=0, c=0;
        for (int i=0; word[i]; i++)
            if (word[i] == 'O')
                sum += ++c;
            else
                c = 0;

        cout << sum << endl;
    }
}
