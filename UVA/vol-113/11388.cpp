#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T, g, l;
    cin>>T;
    while(T--) {
        cin>>g>>l;
        if (l%g) cout << "-1\n";
        else cout << g << " " << l << endl;
    }
}
