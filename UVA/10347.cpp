#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

double p2(double x) {
	double t = x*x;
	return t*t;
}

double trarea(double x, double y, double m) {
	x = 2*x/3;
	y = 2*y/3;
	m = m/3;

	if (x == y) {
		if (m>=x) return -1;
		return m*sqrt(x*x - m*m);
	}

	double x2 = x*x;
	double y2 = y*y;
	double m2 = m*m;

	double t = (x2*x2-y2*y2)/(2*(x2-y2));
	if (t <= m2) return -1;
	double c = 2 * sqrt(t - m2);
	
	if (x+y<=c || x+c<=y || y+c<=x) return -1;
	double s = (x+y+c)/2;
	return sqrt(s*(s-x)*(s-y)*(s-c));
}

double area(double a, double b, double c) {
	if (a<=0 || b<=0 || c<=0) return -1;

	double t1 = trarea(a, b, c);
	if (t1<0) return -1;

	double t2 = trarea(a, c, b);
	if (t2<0) return -1;

	double t3 = trarea(b, c, a);
	if (t3<0) return -1;

	double r = t1+t2+t3;
	if (r < 0.0005) return -1;
	return r;
}

int main(){
	double a, b, c;
	while (cin>>a>>b>>c)
		printf("%.3f\n", area(a,b,c));
}
