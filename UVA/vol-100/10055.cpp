#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	long long int x, y;
	while (cin>>x>>y)
		cout << (x<y?y-x:x-y)<<endl;
}
