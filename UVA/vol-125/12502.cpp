#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, a, b, m;
    cin>>T;
    while(T--) {
        cin>>a>>b>>m;
        cout << (3*a*m)/(a+b)-m << endl;
    }
}
