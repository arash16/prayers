#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int n;
	for(int cse=1; cin>>n && n>=0; cse++)
		printf("Case %d: %d\n", cse, !n ? 0 : int(ceil(log2(n))));
}

