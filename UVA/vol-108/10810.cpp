#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int a[500011], b[500011];
long long qs(int s, int e) {
	if (s+1>=e) return 0;
	long long c=0;
	int piv = a[s],
		j=s, k=0;

	for (int i=s; i<e; i++)
		if (a[i] < piv) {
			c += i-j;
			a[j++] = a[i];
		}
		else b[k++] = a[i];

	int mid = j;
	for (int i=0; i<k; i++)
		a[j++] = b[i];

	return c + qs(s, mid) + qs(mid+1, e);
}

int main(){
	int n;
	while (cin>>n && n) {
		for (int i=0; i<n; i++)
			cin >> a[i];
		cout << qs(0, n) << endl;
	}
}
