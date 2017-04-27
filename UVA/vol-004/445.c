/*
  >>~~ ACM PROBLEM ~~<<

  ID: 445
  Name: Marvelous Mazes
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

int main(){
 char line[140],c;
 int i=0,n=0,j;

 while (gets(line)){
   i=0;
   while(line[i]){
      c=line[i++];
      if(c=='!')printf("\n");
      else if((c>47)&&(c<58))n+=c-48;
      else{
         if(c=='b')c=' ';
         for(j=0;j<n;j++)printf("%c",c);
         n=0;
      }
   }
   printf("\n");
 }
 return 0;
}
