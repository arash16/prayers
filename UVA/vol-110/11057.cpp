#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int nums[10005];
int find(int n, int m) {
    int k = lower_bound(nums, nums + n, m >> 1) - nums;
    if (nums[k] << 1 == m)
        if (nums[k + 1] == nums[k])
            return nums[k];
        else k--;

    for (int i = k; i >= 0; i--)
        if (binary_search(nums, nums + n, m - nums[i]))
            return nums[i];
    return 0;
}


int main() {
    int n, m;
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cin >> m;
        sort(nums, nums + n);
        int res = find(n, m);
        res = min(res, m - res);
        printf("Peter should buy books whose prices are %d and %d.\n\n", res, m - res);
    }
}