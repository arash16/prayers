#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int a, b;
	while(cin>>a>>b && (a!=-1 || b!=-1)) {
		int diff = a>b ? a-b : b-a;
		cout << min(diff, 100-diff) << endl;
	}
}
