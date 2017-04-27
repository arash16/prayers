#include <stdio.h>
#include <set>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int match(char *s1,char *s2){  //s1 in s2
    int i;
    for(i=0;s1[i];i++)
        if(s1[i]!=s2[i])
            return i;
    return i;
}

int main(){
    set<string> l;
    set<string>::iterator i,j,s,e;
    set<string> op;
    int k;
    char t[40];
    while(gets(t))
        l.insert(t);
    for(i=l.begin();i!=l.end();i++){
        s=l.lower_bound(*i);s++;
        for(j=s;j!=l.end();j++){
            if(i!=j && (k=match((char*)&(*i)[0],(char*)&(*j)[0]))==strlen((char*)&(*i)[0]) && l.count(j->substr(k)))
                op.insert(*j);
            if(!k)break;
        }
    }
    for(i=op.begin();i!=op.end();i++)
        printf("%s\n",&(*i)[0]);
}