#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;


struct line{
    int s,e;
    bool operator<(const line &t)const{
        if(s!=t.s)return s<t.s;
        else return e>t.e;
    }
};

line a[100001];
bool ch[100001];
int main(){
    int T,i,j,k,m,n,cnt,cur;

    cin>>T;
    while(T--){
        cin>>m;
        n=0;
        while(scanf("%d%d",&a[n].s,&a[n].e)==2 && (a[n].s||a[n].e))
            ch[n++]=0;

        sort(a,a+n);
        cur=cnt=0;

        for(i=0;i<n && cur<m && a[i].s<=cur;i++){
            for(k=j=i;j<n && a[j].s<=cur;j++)
                if(a[j].e>a[k].e)
                    k=j;

            ch[k]=1;
            cnt++;
            cur=a[k].e;
            i=k;
        }

        if(cur>=m){
            cout<<cnt<<endl;
            for(i=0;i<n && cnt;i++)
                if(ch[i])
                    printf("%d %d\n",a[i].s,a[i].e),cnt--;
        }else
            cout<<0<<endl;

        if(T)cout<<endl;
    }
}