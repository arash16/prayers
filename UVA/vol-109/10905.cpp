#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool com (const string& s1, const string& s2)  {
	return s1+s2 > s2+s1;
}

int main(){
	int n;
	string nums[55];

	while (cin>>n && n) {
		for (int i=0; i<n; i++)
			cin>>nums[i];

		sort(nums, nums+n, com);
		for (int i=0; i<n; i++)
			cout<<nums[i];
		cout<<endl;
	}
}

