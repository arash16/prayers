#include <stdio.h>
#include <iostream>
using namespace std;

// 1   5   10   25   50
// a + 5b +10c +25d +50e = n
int coins[] = {1, 5, 10, 25, 50};
long long int DP[30001][5];
int main() {
	for (int i=0; i<2; i++)
		for(int j=0; j<5; j++)
			DP[i][j]=1;

	for (int i=2; i<30001; i++) {
		DP[i][0] = 1;
		for (int j=1; j<5; j++)
			for (int k=0; k*coins[j]<=i; k++)
				DP[i][j] += DP[i-k*coins[j]][j-1];
	}
	
	int n;
	while(cin>>n)
		if (n<5)
			printf("There is only 1 way to produce %d cents change.\n", n);
		else
			printf("There are %lld ways to produce %d cents change.\n", DP[n][4], n);
}
