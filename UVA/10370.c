/*
  >>~~ ACM PROBLEM ~~<<

  ID: 10370
  Name: Ugly Numbers
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

int main(){
 int n,m,i,sum,g[1000],c;
 float avg;
 
 scanf("%d",&m);
 while (m--){
    if(scanf("%d",&n)==-1)break;
    sum=c=0;
    for(i=0;i<n;i++){
      scanf("%d",&g[i]);
      sum+=g[i];
    }
    avg=sum/n;
    for(i=0;i<n;i++)if(g[i]>avg)c++;
    printf("%.3f%%\n",((float)c)*100/n);
 }
 return 0;
}
