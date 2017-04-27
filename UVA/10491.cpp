#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	double c,w,s;
	while (cin>>w>>c>>s) {
		double sum=c+w;
		printf("%.5f\n", c*(sum-1)/(sum*(sum-s-1)));
	}
}
