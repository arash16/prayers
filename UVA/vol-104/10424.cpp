#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int dec(int x) {
    if (x<10) return x;

    int s = 0;
    for(; x; x/=10)
        s+=x%10;
    return dec(s);
}

int val(char s[]) {
    int r = 0;
    for(int i=0; s[i]; i++)
        if (s[i]>='A' && s[i]<='Z')
            r+=s[i]-'A'+1;
        else if (s[i]>='a' && s[i]<='z')
            r+=s[i]-'a'+1;

    return dec(r);
}

int main(){
    char nx[100], ny[100];
    while(cin.getline(nx, 100) && cin.getline(ny, 100) && (nx[0] || ny[0])) {
        int x = val(nx),
            y = val(ny);

        printf("%.2f \%\n", 100.0*min(x,y)/max(x,y));
    }
}
