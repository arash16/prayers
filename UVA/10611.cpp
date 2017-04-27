#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n, q, h, ladies[50001];
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>ladies[i];
	
	cin>>q;
	for (int i=0; i<q; i++) {
		cin>>h;
		auto r = equal_range(ladies, ladies+n, h);
		int lo=r.first-ladies-1, hi=r.second-ladies;
		if (lo>=0) cout << ladies[lo] << " ";
		else cout << "X ";
		
		if (hi<n) cout<< ladies[hi] << endl;
		else cout<<"X\n";
	}
}
