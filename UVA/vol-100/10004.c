/*
  >>~~ ACM PROBLEM ~~<<

  ID: 10004
  Name: Bicoloring
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

char m[201][201];
int n,l,e,c[201];

void colorit(int,int);
void colorit(int x,int color)
{
  int i;
  c[x]=color;
  for(i=0;i<l;i++)if(m[x][i]){
    if(c[i]==color){e=1;return;}
    else if(!c[i])colorit(i,-1*color);
  }
}

int main(){
 int i,j,a,b;
 
 while (scanf("%d",&n)!=-1){
   if(!n)return 0;
   scanf("%d",&l);
   
   for(i=0;i<201;i++)
     for(j=0;j<201;j++){
       m[i][j]=c[i]=0;}
       
   for(i=0;i<l;i++)
   {
     scanf("%d %d",&a,&b);
     m[a][b]=m[b][a]=1;
   }
   
   e=0;colorit(a,1);
   if(e) printf("NOT BICOLORABLE.\n");
   else  printf("BICOLORABLE.\n");
 }
 return 0;
}
