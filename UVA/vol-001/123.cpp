#include <stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

map<string, bool> ig;
map<string, list<string> > id;

int main(){
    char ln[500], ln2[500], ln3[500];
    while (cin.getline(ln, 500) && ln[0]!=':')
        ig[ln] = 1;

    while (cin.getline(ln, 500)) {
        for (int i=0; !i || ln[i-1]; i++)
            ln[i] = ln2[i] = tolower(ln[i]);

        for (char *w=strtok(ln, " "); w; w=strtok(0, " "))
            if (!ig[w]) {
                strcpy(ln3, ln2);
                for (int i=w-ln; ln[i]; i++)
                    ln3[i] = toupper(ln3[i]);

                id[w].push_back(ln3);
            }
    }

    for (auto &it: id)
        for (string ln: it.second)
            cout << ln << endl;
}
