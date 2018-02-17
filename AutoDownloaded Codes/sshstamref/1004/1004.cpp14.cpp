#include <stdio.h>
#include <stdlib.h>

int main()
{
  int T,n;                        //Test case
  int x1,y1,x2,y2;          //start end
  int planet[50][3];       //planet array
  int i,j,C;                       //for integer
  int p_1,p_2;
    
  scanf("%d",&T);
  for(i=0;i<T;i++){
  	   scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
           scanf("%d",&n);
           C=0;
   
           for(j=0;j<n;j++)
                scanf("%d %d %d",&planet[j][0],&planet[j][1],&planet[j][2]);
           
   for(j=0;j<n;j++){
        	p_1 = (x1-planet[j][0])*(x1-planet[j][0])+(y1-planet[j][1])*(y1-planet[j][1]);
           	p_2 = (x2-planet[j][0])*(x2-planet[j][0])+(y2-planet[j][1])*(y2-planet[j][1]);

if(p_1 < planet[j][2]*planet[j][2] && p_2 < planet[j][2]*planet[j][2]);
else if(p_1 < planet[j][2]*planet[j][2] || p_2 < planet[j][2]*planet[j][2]){
C++;
}
        	}
        	printf("%d\n",C);
  }
  return 0;
}

