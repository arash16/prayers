#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	long long int fib[52] = {1, 2};
	for (int i=2; i<52; i++)
		fib[i] = fib[i-1] + fib[i-2];
	fib[0]=0;
	
	int T, n;
	cin>>T;
	for (int cse=1; cse<=T; cse++) {
		cin>>n;
		printf("Scenario #%d:\n%lld\n\n", cse, fib[n]);
	}
}
