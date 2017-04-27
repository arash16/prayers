#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	char op[20];
	long long int n, x, s=0;
	cin>>n;
	while(n--) {
		cin>>op;
		if (op[0]=='r') cout<<s<<endl;
		else {
			cin>>x;
			s+=x;
		}
	}
}
