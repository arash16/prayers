#include <stdio.h>
#include <iostream>
using namespace std;

int DP[110] = {0,0, 1,1};
int main(){
    for (int i=4; i<110; i++)
        DP[i] = i/3 + DP[i/3+i%3];

    int n;
    while (cin>>n && n)
        cout << DP[n] << endl;
}
