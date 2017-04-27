#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    char line[1005];
    while(cin>>line && (line[1] || line[0]!='0')) {
        int sum = 0;
        for(int i=0; line[i]; i++)
            sum += (i%2 ? -1 : 1) * (line[i]-'0');
        cout << line << " is" << (sum%11 ? " not" : "") <<" a multiple of 11.\n";
    }
}
