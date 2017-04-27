#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;


char line[10000];
int main() {
    int n;
    cin>>n;
    cin.getline(line,10);
    while(n--) {
        cin.getline(line, 10000);
        int l = strlen(line);
        if (l==1 || (l==2 && line[0]=='7' && line[1]=='8'))
            cout<<"+\n";
        else if(l>1 && line[l-2]=='3' && line[l-1]=='5')
            cout<<"-\n";
        else if(l>1 && line[0]=='9' && line[l-1]=='4')
            cout<<"*\n";
        else if(l>2 && line[0]=='1' && line[1]=='9' && line[2]=='0')
            cout<<"?\n";
        else cout<<"+\n";
    }
}
