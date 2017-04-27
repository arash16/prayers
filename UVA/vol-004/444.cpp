#include <stdio.h>
#include <cstring>
#include <iostream>
using namespace std;

bool isc[130];
char rev[130][4];

void encode(char* s) {
    for (int i=strlen(s)-1; i>=0; i--)
        cout << rev[s[i]];
    cout<<endl;
}

void decode(char* s) {
    int num=0;
    for (int i=strlen(s)-1; i>=0; i--) {
        num = num*10 + s[i] - '0';
        if (isc[num]) {
            cout << (char)num;
            num = 0;
        }
    }
    cout << endl;
}

int main(){
    for (int i=0; i<26; i++)
        isc['A'+i] = isc['a'+i] = 1;
    isc[32]=isc[33]=isc[44]=isc[46]=isc[58]=isc[59]=isc[63]=1;

    for (int i=32; i<130; i++)
        if (isc[i]) {
            int r = 0;
            for (int n=i; n; n/=10)
                rev[i][r++] = '0' + n%10;
            rev[i][r]=0;
        }

    char line[1000];
    while(cin.getline(line, 1000)) {
        if (line[0]>='0' && line[0]<='9')
            decode(line);
        else
            encode(line);
    }
}
