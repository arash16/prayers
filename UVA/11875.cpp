#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int cse=1; cse<=t; cse++) {
		int n, x;
		cin>>n;
		for (int i=0; i<=n/2; i++)
			cin>>x;
		printf("Case %d: %d\n", cse, x);
		for (int i=0; i<n/2; i++)
			cin>>x;
	}
}
