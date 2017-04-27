#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;

class largeint{
public:
	short int *nums;
	int n_size;
    #define nlen nums[0]
	largeint(int n){
		int i;
		nums=(short int *)malloc((n+1)*sizeof(short int));
		memset(nums,0,(n+1)*sizeof(short int));
		n_size=n;
		nums[0]=0;
	}
	~largeint(){
		free(nums);
	}

	void print(){
		if(nlen<0)cout<<'-';
		for(int i=abs(nlen);i>0;i--)cout<<nums[i];
		if(!nlen)cout<<'0';
	}
	void fixlen(int s){
		int i;
		for(i=n_size;!nums[i] && i>0;i--);
		nlen=i*s;
	}

	largeint& operator=(const largeint &b){
		int i;
		for(i=0;i<=abs(b.nlen);i++)nums[i]=b.nums[i];
		return *this;
	}
	largeint& operator=(const char* b){
		nlen=strlen(b);
		for(int i=0;b[i];i++)nums[nlen-i]=b[i]-48;
		return *this;
	}

	largeint& operator+=(const largeint &b){ 
		if(n_size!=b.n_size)throw;
		int i;
		for(i=1;i<=abs(b.nlen);i++){
			nums[i]+=b.nums[i];
			nums[i+1]+=nums[i]/10;
			nums[i]%=10;
		}
		for(;nums[i];i++){
			nums[i+1]+=nums[i]/10;
			nums[i]%=10;
		}
		fixlen(1);
		return *this;
	}
};


int main(){
	char t[5];
	int i,n;
	while(scanf("%d",&n)==1)
	{ largeint t1(1500),t2(1500),t3(1500);
	  t1="0";
	  t2="1";
	  for(i=0;i<n;i++){
		t3=t2;
	 	t2+=t1;
		t1=t3;
	  }
	  t1.print();
	  cout<<endl;
	}
	return 0;
}