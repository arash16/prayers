#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int h1, m1, h2, m2;
    while (cin>>h1>>m1>>h2>>m2 && (h1||m1||h2||m2))
        cout << ( (h2*60+m2 - h1*60-m1 + 24*60) % (24*60) ) << endl;
}
