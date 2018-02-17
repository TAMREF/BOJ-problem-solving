//Ford-Fulkerson
#include <bits/stdc++.h>
#define flow 0
#define sink N+M+1
#define loop(x,y) for(int i=x;i<=y;i++)
using namespace std;
const int MX = 404;
int N, M, a, b, ans, edge[MX][MX];
bool visit[MX];
vector<int> before(MX);
bool dfs(int s){
    if(s==sink) return true;
    loop(flow,sink){
        if(edge[s][i]<=0 || visit[i]) continue;
        visit[i]=true;
        before[i]=s;
        if(dfs(i)) return true;
    }
    return false;
}
void gb(int now){
    for(;now;){
        int tmp = before[now];
        --edge[tmp][now];
        ++edge[now][tmp];
        now=tmp;
    }
}
int main(){
    scanf("%d%d",&N,&M);
    loop(1,N){
        for(scanf("%d",&a);a--;){
            scanf("%d",&b);
            edge[i][N+b]=1;
        }
    }
    loop(1,N) edge[flow][i]=1;
    loop(1,M) edge[N+i][sink]=1;
    while(dfs(flow)){
        ++ans;
        gb(sink);
        fill(visit,visit+sink+1,false);
    }
    printf("%d\n",ans);
}