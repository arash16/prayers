#include <stdio.h>
#include <iostream>
using namespace std;

int DP[60]={0, 1};
int main(){
	for (int i=2; i<52; i++)
		DP[i] = DP[i-1] + i + (i&1);

	int T, n;
	cin>>T;
	while (T--) {
		cin>>n;
		cout << DP[n] << endl;
	}
}
