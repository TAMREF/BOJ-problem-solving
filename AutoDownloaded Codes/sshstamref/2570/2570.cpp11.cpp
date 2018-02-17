#include <bits/stdc++.h>
using namespace std;
const int MX = 210, NX=6002;
short s, t=6001, K=3000;
int N, M, ans, x, y;
short bef[NX], L[MX][MX], R[MX][MX];
vector<short> edge[NX];
short lnum, rnum;
bool vis[NX], tam[NX][NX], chess[MX][MX];
void input(){
    for(scanf("%d%d",&N,&M);M--;){
        scanf("%d%d",&x,&y);
        chess[x][y]=true;
    }
    for(int d=N-1;d>-N;d--){
        short flag = 1;
        for(int c=max(1,-d+1);c<=N&&c+d<=N;c++){
            if(chess[c+d][c]) flag=1;
            else{
                lnum+=flag; flag=0;
                L[c+d][c]=lnum;
                tam[s][lnum]=true;
                edge[s].push_back(lnum);
            }
        }
    }
    for(int S=2;S<=2*N;S++){
        int flag=1;
        for(int c=max(1,S-N);S>c&&c<=N;c++){
            if(chess[S-c][c]) flag=1;
            else{
                rnum+=flag; flag=0;
                R[S-c][c]=rnum;
                tam[K+rnum][t]=true;
                edge[K+rnum].push_back(t);
            }
        }
    }
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(!chess[i][j]){
                tam[L[i][j]][K+R[i][j]]=true;
                edge[L[i][j]].push_back(K+R[i][j]);
                edge[K+R[i][j]].push_back(L[i][j]);
            }
}
bool dfs(short now){
    if(now==t) return true;
    for(short &i : edge[now]){
        if(!tam[now][i] || vis[i]){
            continue;
        }
        vis[i]=true; bef[i]=now;
        if(dfs(i)) return true;
    }
    return false;
}
void goback(){
    for(short now=t;now!=0;now=bef[now]){
        tam[bef[now]][now]=false;
        tam[now][bef[now]]=true;
    }
}
int main(){
    input();
    while(dfs(s)){
        ++ans;
        goback();
        fill(vis,vis+t+1,false);
    }
    printf("%d",ans);
}
