#include <bits/stdc++.h>
using namespace std;
const int t=1<<8;
int N, K, a[t+1][t+1][t+1], c[t+1][t+1][t+1], e[t+1];
bool musubi(int d){
    for(int i=1;i+d<=t;i++){
        for(int j=1;j+d<=t;j++){
            for(int k=1;k+d<=t;k++){
                if(a[i+d][j+d][k+d]-a[i-1][j+d][k+d]-a[i+d][j-1][k+d]-a[i+d][j+d][k-1]+a[i-1][j-1][k+d]+a[i-1][j+d][k-1]+a[i+d][j-1][k-1]-a[i-1][j-1][k-1]>=K){
                    e[d]=(i-1<<16)+(j-1<<8)+k-1;
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&N,&K);
    for(int i=0,r,g,b;i<N;i++){
        scanf("%d%d%d",&r,&g,&b);
        ++c[r+1][g+1][b+1];
    }
    for(int i=1;i<=t;i++)
        for(int j=1;j<=t;j++)
            for(int k=1;k<=t;k++)
                a[i][j][k]=c[i][j][k]+a[i-1][j][k]+a[i][j-1][k]+a[i][j][k-1]-a[i-1][j-1][k]-a[i-1][j][k-1]-a[i][j-1][k-1]+a[i-1][j-1][k-1];
    int l=0, h=255, ans=255, m;
    while(l<=h){
        m=(l+h)>>1;
        if(musubi(m)){
            h=m-1;
            ans=ans<m?ans:m;
        }
        else l=m+1;
    }
    printf("%d\n",ans);
    int x=(e[ans]>>16)+1,y=(e[ans]>>8)%t+1,z=e[ans]%t+1;
    for(int i=0,cnt=0;i<=ans;i++)
        for(int j=0;j<=ans;j++)
            for(int k=0;k<=ans;k++)
                while(c[i+x][j+y][k+z]--){
                    printf("%d %d %d\n",i+x-1,j+y-1,k+z-1);
                    if(++cnt>=K) return 0;
                }
}
