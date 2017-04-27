#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	long long T, n;
	cin>>T;
	while (T--) {
		cin>>n;
		cout << (int) floor((1 + sqrt(1 + (long double)8*n))/2)-1 << endl;
	}
}
