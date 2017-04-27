#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct mpair{
	int a,ab;
	bool operator<(const mpair &t)const{
		return ab<t.ab;
	}
};

int main(){
	int n,i,j,t,ans=0;
	mpair tt;
	multiset<mpair>::iterator wh;
	multiset<mpair> sums;
	int nums[1000];
	bool found;

	while(scanf("%d",&n)==1 && n>0){
		sums.clear();
		for(i=0;i<n;i++)
			scanf("%d",nums+i);
		for(i=0;i<n;i++)
			for(j=i+1;j<n;j++)
			{
				tt.a=tt.ab=nums[i];
				tt.ab+=nums[j];
				sums.insert(tt);
			}
				
		found=0;
		for(i=n-1;i>=0;i--)
			for(j=n-1;j>=0;j--)
			if(i!=j)
			{
				tt.ab=nums[i]-nums[j];
				for(wh=sums.find(tt);wh!=sums.end() && wh->ab==tt.ab;wh++){
				  if(wh->a==nums[i] || wh->a==nums[j] || 
				    (wh->ab-wh->a==nums[i]) || (wh->ab-wh->a==nums[j]))continue;
				  if(nums[i]>ans || !found)
					  ans=nums[i];
				  found=1;
				  break;
				}
			}
		if(found)
			printf("%d\n",ans);
		else printf("no solution\n");
	}
	return 0;
}