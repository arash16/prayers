/*
  >>~~ UVa Online Judge ACM Problem Solution ~~<<

  ID: 488
  Name: Triangle Wave
  Problem: https://onlinejudge.org/external/4/488.pdf
  Language: C

  Author: Arash Shakery
  Email: arash.shakery@gmail.com
*/

int main(){
 int fi=0,a,f,i,j,k,n;

 scanf("%d",&n);
 while (n--){
    if(scanf("%d%d",&f,&a)==-1)break;
    if(fi)printf("\n"); fi=1;
    for(i=0;i<a;i++){
       if(i)printf("\n");
       for(j=0;j<2*f-1;j++){
         for(k=0;k<f-abs(f-j-1);k++)
           printf("%d",f-abs(f-j-1));
         printf("\n");
       }
    }
 }
 return 0;
}
