#include <bits/stdc++.h>
#define flow 0
#define sink N+M+1
using namespace std;
const int MX = 1003;
int N, M, a, b, i, ans;
int tam[2*MX][2*MX];
bool vis[2*MX];
stack<int> before;
bool dfs(int st){
    if(st==sink) return true;
    for(int j=flow;j<=sink;j++){
        if((tam[st][j]<=0)||(vis[j]==true)) continue;
        before.push(st);
        vis[j]=true;
        if(dfs(j)) return true;
    }
    before.pop();
    return false;
}
void goback(int now){
    for(;!before.empty();before.pop()){
        int tmp = before.top();
        vis[now]=false;
        --tam[tmp][now];
        ++tam[now][tmp];
        now=tmp;
    }
}
int main(){
    scanf("%d %d",&N,&M);
    for(i=1;i<=N;i++){
        for(scanf("%d",&a);a--;){
            scanf("%d",&b); tam[i][N+b]=1;
        }
    }
    for(i=1;i<=N;i++) tam[flow][i]=2;
    for(i=1;i<=M;i++) tam[N+i][sink]=1;
    while(dfs(flow)){
        ++ans;
        goback(sink);
        for(i=flow;i<=sink;i++) vis[i]=false;
    }
    printf("%d",ans);
}
