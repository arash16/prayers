#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int cse=1;
	long long n;
	while (cin>>n && n)
		printf("Case %d: %d\n", cse++, (int)ceil(1+(1+sqrt(9+8*n))/2));
}
