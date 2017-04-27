#include <stdio.h>
#include <iostream>
using namespace std;

#define MXM 10000
struct Mat2 {
	int a, b, c, d;
	Mat2(int a, int b, int c, int d):a(a%MXM),b(b%MXM),c(c%MXM),d(d%MXM){}
	Mat2 operator *(const Mat2 m) const {
		return Mat2(a*m.a+b*m.c, a*m.b+b*m.d, c*m.a+d*m.c, c*m.b+d*m.d);
	}
};

Mat2 one(1,0,1,0);
Mat2 powmod(Mat2 x, int n) {
	if (n == 0) return one;
	if (n == 1) return x;
	
	Mat2 x2 = powmod(x, n>>1);
	Mat2 tx2 = x2 * x2;
	return (n&1) ? tx2*x : tx2;
}


Mat2 fib(1,1,1,0);
int mm[] = {1, 10, 100, 1000, 10000};
int main(){
	int T, n, a, b, m, res;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &a, &b, &n, &m);

		if (!n) printf("%d\n", a);
		else {
			Mat2 an = powmod(fib, n - 1);
			int result = (an.a*b + an.b*a) % mm[m];
			printf("%d\n", result);
		}
	}
}
