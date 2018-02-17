#include <bits/stdc++.h>
using namespace std;
int s[3][2], N;
int main(){
    scanf("%d",&N);
    for(int i=0;i<3;i++) for(int j=0;j<2;j++) scanf("%d",&s[i][j]);
    for(int x=0,y;x<=s[0][0];x++){
        y = s[0][0] - x;
        if(y<0||y>s[0][0]) continue;
        y = s[2][1] - y;
        if(y<0||y>s[1][0]) continue;
        y = s[1][1] - x;
        if(y<0||y>s[2][0]) continue;
        y = s[0][1] - s[2][0] + y;
        if(y<0||y>s[1][0]) continue;
        puts("1");
        printf("%d %d\n",x,s[0][0]-x);
        printf("%d %d\n",s[0][1]-s[2][0]+s[1][1]-x,s[2][1]-s[0][0]+x);
        printf("%d %d\n",s[2][0]-s[1][1]+x, s[1][1]-x);
        return 0;
    }
    puts("0");
}