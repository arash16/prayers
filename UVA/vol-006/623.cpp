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
    largeint(int n=2580){
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

    largeint& operator*=(const largeint &b){
        int i,j;
        largeint c(n_size);
        for(i=1;i<=nlen;i++)
            for(j=1;j<=b.nlen;j++)
                c.nums[i+j-1]+=nums[i]*b.nums[j];

        for(i=1;i<=nlen+b.nlen;i++){
            c.nums[i+1]+=c.nums[i]/10;
            c.nums[i]%=10;
        }
        c.fixlen((nlen*b.nlen)/abs(nlen*b.nlen));
        *this=c;
        return *this;
    }
};

int main(){
    register int n,i;
    char kk[5];
    largeint sa[1001],p,p2(5);
    sa[0]=p="1";
    for(i=1;i<=1000;i++)
    {
        sprintf(kk,"%d",i);
        p2=kk;
        p*=p2;
        sa[i]=p;
    }
    while(scanf("%d",&n)==1){
        printf("%d!\n",n);
        sa[n].print();
        printf("\n");
    }
    return 0;
}