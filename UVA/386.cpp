#include <math.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct P {
	int a, b, c, d;
	bool operator < (const P& o) const {
		if (a==o.a)
			return b==o.b ? c<o.c : b<o.b;
		return a<o.a;
	}
};

int sqr3(int x) {
	return x*x*x;
}

double sqrt3(int x) {
	return pow(2, log2(x)/3.0);
}


int main(){
	int a3;
	int l = 0;
	P arr[2000], t;
	for (t.b=2; t.b<200; t.b++)
		for (t.c=t.b; t.c<200; t.c++)
			for (t.d=t.c; t.d<200; t.d++) {
				t.a = round(sqrt3(a3 = sqr3(t.b) + sqr3(t.c) + sqr3(t.d)));
				if (t.a<=200 && sqr3(t.a) == a3)
					arr[l++] = t;
			}
	sort(arr, arr+l);
	for (int i=0; i<l; i++)
		printf("Cube = %d, Triple = (%d,%d,%d)\n", arr[i].a, arr[i].b, arr[i].c, arr[i].d);
}
