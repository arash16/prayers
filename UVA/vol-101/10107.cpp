#include <stdio.h>
#include <iostream>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;


    int x;
    while (cin >> x) {
        if (!right.size() || x < right.top())
            left.push(x);
        else right.push(x);

        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size() + 1) {
            left.push(right.top());
            right.pop();
        }

        if (left.size() == right.size())
            cout << ((left.top() + right.top()) >> 1) << endl;
        else if (left.size() > right.size())
            cout << left.top() << endl;
        else
            cout << right.top() << endl;
    }
}