#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int T, n;
	cin>>T;
	while (T--) {
		cin>>n;n*=n;
		printf("%.2f %.2f\n", 0.125663706144*n, 0.474336293856*n);
	}
}
