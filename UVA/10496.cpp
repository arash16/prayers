#include <stdio.h>
#include <iostream>
using namespace std;

struct point{
	int x,y;
};

point beeper[12];
int dist(int a, int b){
	return abs(beeper[a].x-beeper[b].x)+abs(beeper[a].y-beeper[b].y);
}

int used[12],n,best;
bool check(int lb, int d, int i){
	if(used[i])return 0;
	if(d+dist(lb,i)>=best)return 0;
	return 1;
}

void BT(int lb, int d, int c){
	if(c==n)
	{
		if(d+dist(lb,0)<best)
			best=d+dist(lb,0);
		return;
	}

	for(int i=1; i<=n; i++)
		if(check(lb,d,i))
		{
			used[i]=1;
			BT(i,d+dist(lb,i),c+1);
			used[i]=0;
		}
}

int main(){
	int cse,width,height;
	cin>>cse;
	while(cse--){
		cin>>width>>height;
		cin>>beeper[0].x>>beeper[0].y;
		cin>>n;
		for(int i=1; i<=n; i++)
			cin>>beeper[i].x>>beeper[i].y;

		best=100000;
		BT(0,0,0);
		printf("The shortest path has length %d\n",best);
	}
}