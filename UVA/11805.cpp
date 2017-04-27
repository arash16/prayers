#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int cse=1; cse<=t; cse++) {
		int n,k,p,r;
		cin>>n>>k>>p;
		r=(k+p)%n;
		printf("Case %d: %d\n", cse, r ? r : n);
	}
}
