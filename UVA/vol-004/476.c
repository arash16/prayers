/*
  >>~~ ACM PROBLEM ~~<<

  ID: 476
  Name: Points in Figures: Rectangles
  Author: Arash Shakery
  Email: arash.shakery@gmail.com
  Language: C
*/

struct rectangle{float x1,y1,x2,y2;} r[11];

int bt(float x,float s,float e){
     return (((x>s)&&(x<e))||((x<s)&&(x>e)));
}

int main(){
 int i=0,j,rcount,found;
 float p1,p2;
 char c;

 while (scanf("%c",&c)!=-1){
    if(c!='r')break;
    scanf("%f%f%f%f\n",&r[i].x1,&r[i].y1,&r[i].x2,&r[i].y2);
    i++;
 }
 rcount=i;

 j=1;
 while (scanf("%f%f",&p1,&p2)!=-1){
    if((p1>9999)&&(p2>9999))break;
    found=0;
    for(i=0;i<rcount;i++)
      if(bt(p1,r[i].x1,r[i].x2)&&(bt(p2,r[i].y1,r[i].y2)))
        {printf("Point %d is contained in figure %d\n",j,i+1);found=1;}
    if(!found)printf("Point %d is not contained in any figure\n",j);
    j++;
 }
 return 0;
}
