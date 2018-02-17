#include <bits/stdc++.h>
using namespace std;
const int MAXV=2005;
int N, M, flow[MAXV][MAXV];
bool vis[MAXV];
vector<int> link[MAXV];
int bef[MAXV];
int s, t;
void input(){
    scanf("%d%d",&M,&N);
    t=N+M+1;
    for(int i=1,a,b;i<=N;i++){
        scanf("%d%d",&a,&b);
        for(int j=a;j<=b;j++){
            flow[i][N+j]=1;
            link[i].push_back(N+j);
            link[N+j].push_back(i);
        }
        flow[s][i]=1;
        link[s].push_back(i);
        link[i].push_back(s);
    }
    for(int i=1;i<=M;i++){
        flow[N+i][t]=1;
        link[N+i].push_back(t);
        link[t].push_back(N+i);
    }
}
bool dfs(int st=s){
    if(st==t) return true;
    for(int u : link[st]){
        if(vis[u]||flow[st][u]<=0) continue;
        vis[u]=true;
        bef[u]=st;
        if(dfs(u)) return true;
    }
    return false;
}
int main(){
    int T;
    for(scanf("%d",&T);T--;){
    for(int i=s;i<=t;i++) link[i].clear();
    memset(flow,0,sizeof(flow));
    fill(vis,vis+t+1,false);
    input();
    int ans=0;
    while(dfs()){
        ++ans;
        for(int now=t;now;now=bef[now]) --flow[bef[now]][now], ++flow[now][bef[now]];
        fill(vis,vis+t+1,false);
    }
    printf("%d\n",ans);
    }
}
