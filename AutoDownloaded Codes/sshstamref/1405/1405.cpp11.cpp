#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int p[4];
const int dx[4]={1,-1,0,0}, dy[4]={0,0,-1,1};
int vis[30][30], N;
ld dfs(int n,int x,int y,int d){
    if(vis[x][y]) return 0;
    if(n==N) return 1;
    vis[x][y]=1;
    ld pc=0;
    for(int e=0;e<4;e++){
        if(e!=(d^1)) pc+=dfs(n+1,x+dx[e],y+dy[e],e)*p[e];
    }
    vis[x][y]=0;
    return pc;
}
void input(){
    cin>>N;
    for(int e=0;e<4;e++){
        cin>>p[e];
        p[e];
    }
}
int main(){
    cin.sync_with_stdio(false); cin.tie(0);
    input();
    ld T=dfs(0,15,15,0b11111);
    for(int i=0;i<N;i++) T/=100.L;
    printf("%.15Lf\n",T);
}