#include <stdio.h>
#include <iostream>
using namespace std;

int nums[20];
bool check() {
	bool f = nums[0] < nums[1];
	for (int i=1; i<10; i++)
		if (f ^ (nums[i-1]<nums[i]))
			return false;
	return true;
}

int main(){
	int n;
	cin>>n;
	cout<<"Lumberjacks:\n";
	while (n--) {
		for (int i=0; i<10; i++)
			cin>>nums[i];
		
		cout << (check() ? "Ordered\n" : "Unordered\n");
	}
}
