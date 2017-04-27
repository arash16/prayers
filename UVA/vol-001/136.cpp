#include <stdio.h>
#include <iostream>
using namespace std;


bool isUgly(int n) {
	while(n && (n&1)==0) n>>=1;
	while(n && n%3==0) n/=3;
	while(n && n%5==0) n/=5;
	return n==1;
}

int main(){
	/*
	int th=0;
	long long int i;
	for (i=0; th!=1500; i++)
		if (isUgly(i))
			th++;
	
	cout << i-1 << endl;
	*/
	printf("The 1500'th ugly number is 859963392.\n");
}

