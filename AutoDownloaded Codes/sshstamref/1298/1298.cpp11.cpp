#include <bits/stdc++.h>
using namespace std;
const int MX=210;
int fl[MX][MX], s, t, N,M, vis[MX];
vector<int> link[MX], bef(MX);
void input(){
    int a, b;
    for(scanf("%d%d",&N,&M);M--;){
        scanf("%d%d",&a,&b);
        fl[a][N+b]=1;
        link[a].push_back(N+b); link[N+b].push_back(a);
    }
    t=2*N+1;
    for(int i=1;i<=N;i++){
        fl[s][i]=fl[N+i][t]=1;
        link[i].push_back(s); link[s].push_back(i);
        link[N+i].push_back(t); link[t].push_back(N+i);
    }
}
bool dfs(int st=0){
    if(st==t) return true;
    for(int &u : link[st]){
        if(fl[st][u]&&!vis[u]){
            bef[u]=st;
            vis[u]=true;
            if(dfs(u)) return true;
        }
    }
    return false;
}
void gb(){
    for(int now=t;now;now=bef[now]){
        --fl[bef[now]][now];
        ++fl[now][bef[now]];
    }
}
int main(){
    input();
    int ans=0;
    while(dfs()){
        ++ans;
        gb();
        fill(vis,vis+t+1,0);
    }
    printf("%d\n",ans);
}
