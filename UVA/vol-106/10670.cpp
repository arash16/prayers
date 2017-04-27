#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
#include <math.h>

using namespace std;

struct agency{
    int a,b;
    int price;
    string name;
    bool operator<(const agency &b)const{
        if(price!=b.price)
          return price<b.price;
        else return name<b.name;
    }
};

int main(){
    int nn,nni,S,T,L,a,b,i,c,j;
    char line[500];
    set<agency> list;
    set<agency>::iterator o;
    agency k;
    string l2;
    scanf("%d",&nn);
    for(nni=1;nni<=nn;nni++){
        list.clear();
        printf("Case %d\n",nni);
        scanf("%d%d%d%*1c",&S,&T,&L);
        for(i=0;i<L;i++){
          scanf("%[^:]%*1c%d%*1c%d%*1c",line,&a,&b);
          for(j=S,c=0;(j/2)>=T && ceil(j/2.0)*a>b;j/=2,c+=b);
          c+=(j-T)*a;
          k.a=a;
          k.b=b;
          k.price=c;
          k.name.assign(line);
          list.insert(k);
        }
        for(o=list.begin();o!=list.end();o++)
            cout<<o->name<<" "<<o->price<<endl;
    }
    return 0;
}