#include <cstdio>
int main(){
printf("%d\n",100);
for(int i=0;i<100; i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i==99) printf("%d ",0);
            else if(j==99) printf("%d ",0);
            else if(i==j) printf("%d ",0);
            else printf("%d ",1000);
        }
        printf("\n");
    }
}