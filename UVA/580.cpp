#include <stdio.h>
#include <iostream>
using namespace std;

int DP[31]={1,2,4};
int main(){
	for (int i=3; i<31; i++)
		DP[i] = DP[i-1] + DP[i-2] + DP[i-3];

	int n;
	while (scanf("%d", &n)==1 && n)
		printf("%d\n", (1<<n) - DP[n]);
}
