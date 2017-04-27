#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int tp, cse=1;
	long double u, v, t, a, s;
	while (cin>>tp && tp) {
		printf("Case %d: ", cse++);

		if (tp==1) cin>>u>>v>>t;
		else if (tp==2) cin>>u>>v>>a;
		else if (tp==3) cin>>u>>a>>s;
		else cin>>v>>a>>s;
		
		if (tp==1) a=(v-u)/t;
		else if (tp==2) t=(v-u)/a;
		if (tp<=2) {
			s=0.5*a*t*t + u*t;
			printf("%.3Lf %.3Lf\n", s, tp==1 ? a : t);
		}
		else {
			if (tp == 3) t = (sqrt(u*u + 2*a*s) - u) / a;
			else t = (-sqrt(v*v - 2*a*s) + v) / a;
			printf("%.3Lf %.3Lf\n", tp==3 ? a*t+u : v-a*t, t);
		}
	}
}
