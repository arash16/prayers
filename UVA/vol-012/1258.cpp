#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef unsigned long long int Long;

Long Fib[92] = {1, 1};
int main(){
	for (int i=2; i<92; i++)
		Fib[i] = Fib[i-1] + Fib[i-2];
	
	Long n;
	while (scanf("%llu", &n)==1) {
		printf("%llu\n", n);
		vector<int> r;
		int lastI = 92;
		for (; n; n -= Fib[lastI]) {
			int ind = upper_bound(Fib, Fib+lastI, n) - Fib;
			if (Fib[ind] > n) --ind;
			printf("%d ", ind);
			r.push_back(ind);
			lastI = ind;
		}
		
		putchar('\n');
		for (int i=0; i<r.size(); i++)
			printf("%llu ", Fib[r[i]]);
		puts("\n");
	}
}
