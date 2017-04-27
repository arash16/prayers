#include <math.h>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(){
    scanf("%*[,.:;!?\"() \t\n]");
    map<string, int> cnts;
    char word[1000];
    int l=0;
    while (scanf("%[^,.:;!?\"() \t\n] %*[,.:;!?\"() \t\n]", word)==1) {
        if (strcmp(word, "****END_OF_INPUT****")==0) break;
        else if (strcmp(word, "****END_OF_TEXT****")==0) {
            double et=0, ll=log10(l);
            for (auto &it: cnts)
                et += it.second * (ll - log10(it.second));
            et /= l;

            printf("%d %.1lf %.0lf\n", l, et, 100*et/ll);
            cnts.clear();
            l=0;
            continue;
        }

        for (int i=0; word[i]; i++)
            word[i] = tolower(word[i]);
        cnts[word]++;
        l++;
    }
}
