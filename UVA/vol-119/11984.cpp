#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int cse=1; cse<=T; cse++) {
        int c, d;
        cin >> c >> d;
        printf("Case %d: %.2f\n", cse, c + 5*d/9.0);
    }
}
