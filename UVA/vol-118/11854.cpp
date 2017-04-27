#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int sizes[3];
    while(cin>>sizes[0]>>sizes[1]>>sizes[2] && (sizes[0]||sizes[1]||sizes[2])) {
        sort(sizes, sizes+3);

        cout << ((sizes[0]*sizes[0] + sizes[1]*sizes[1] == sizes[2]*sizes[2]) ? "right\n" : "wrong\n");
    }
}
