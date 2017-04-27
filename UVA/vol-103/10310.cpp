#include <stdio.h>
#include <math.h>

const int X=0,Y=1;

double dist(double p1[],double p2[2]){
	return sqrt(pow(p1[X]-p2[X],2)+pow(p1[Y]-p2[Y],2));
}

int main(){
	double g[2],d[2],h[2];
	int f,i,n;
	while(scanf("%d %lf%lf%lf%lf",&n,&g[X],&g[Y],&d[X],&d[Y])==5){
		f=0;
		for(i=0;i<n;i++){
			scanf("%lf%lf",&h[X],&h[Y]);
			if(dist(g,h)*2.0<=dist(d,h) && !f){
				f=1;
				printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",h[X],h[Y]);
			}
		}
		if(!f)printf("The gopher cannot escape.\n");
	}
}