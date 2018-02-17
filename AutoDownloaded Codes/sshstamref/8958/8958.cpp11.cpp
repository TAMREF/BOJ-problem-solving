#include <bits/stdc++.h>
using namespace std;
char buf[86];
int main(){
    int t;
    for(int xdx,sum,len=scanf("%d",&t);t--;){
        sum=0,xdx=-1;
        scanf("%*c%s",buf);
        len=strlen(buf);
        for(int i=0;i<len;i++){
            if(buf[i]=='X') xdx=i;
            sum+=i-xdx;
        }
        printf("%d\n",sum);
    }
}