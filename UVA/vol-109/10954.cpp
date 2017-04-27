#include <stdio.h>
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n, x;
    while (cin>>n && n) {
        priority_queue<int, vector<int>, greater<int> > nums;

        for (int i=0; i<n; i++) {
            cin>>x;
            nums.push(x);
        }

        long long int res=0, sum;
        while (nums.size() > 1) {
            sum = nums.top(); nums.pop();
            sum += nums.top(); nums.pop();
            nums.push(sum);
            res += sum;
        }

        cout<<res<<endl;
    }
}

