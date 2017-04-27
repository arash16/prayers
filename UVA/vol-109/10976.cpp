#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int k;
    while (cin>>k) {
        vector<int> bs;
        for (int b = k<<1; b > k; b--)
            if ((k*b) % (b-k) == 0)
                bs.push_back(b);

        cout << bs.size() << endl;
        for (int i=bs.size()-1; i>=0; i--) {
            int b = bs[i];
            printf("1/%d = 1/%d + 1/%d\n", k, k*b/(b-k), b);
        }
    }
}
