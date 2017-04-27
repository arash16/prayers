#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T, x[4];
    cin>>T;
    while(T--) {
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        sort(x, x+4);

        if (x[0]==x[1] && x[2]==x[3])
            cout<< (x[1]==x[2] ? "square\n" : "rectangle\n");
        else if (x[3] < x[0]+x[1]+x[2])
            cout << "quadrangle\n";
        else
            cout << "banana\n";
    }
}
