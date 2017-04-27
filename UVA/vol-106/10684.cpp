#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    int n;
    while (cin>>n && n) {
        int maxs = 0, sum=0, x;
        while (n--)    {
            cin >> x;
            sum += x;
            if (sum < 0) sum = 0;
            if (sum > maxs) maxs = sum;
        }

        if (maxs > 0)
            printf("The maximum winning streak is %d.\n", maxs);
        else
            printf("Losing streak.\n");
    }
}
