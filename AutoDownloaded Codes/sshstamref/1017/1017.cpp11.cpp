#include <bits/stdc++.h>
using namespace std;
const int MX=55;
vector<int> num[2], cand;
int N, my, tmp, sink, exc, flow[MX][MX], sz, vis[MX], bef[MX], flow_init[MX][MX];
void input(){
    scanf("%d",&N);
    scanf("%d",&tmp);
    num[my=tmp&1].push_back(tmp);
    for(int i=1;i<N;i++){
        scanf("%d",&tmp);
        num[tmp&1].push_back(tmp);
    }
    if(num[0].size()!=num[1].size()) exit(0*puts("-1"));
    sz=num[0].size();
    sink=N+1;
}
inline int isprime(int x){
    assert(x>0);
    if(x<3) return x-1;
    if(x&1==0) return 0;
    for(int i=3;i*i<=x;i+=2) if(x%i==0) return 0;
    return 1;
}
bool dfs(int st){
    if(st==sink) return true;
    for(int i=0;i<=sink;i++){
        if(i==(!my)*sz+exc||i==my*sz+1||flow[st][i]<=0||vis[i]) continue;
        vis[i]=1;
        bef[i]=st;
        if(dfs(i)) return true;
    }
    return false;
}
void setting_initial(){
    memset(flow_init,0,sizeof(flow_init));
    for(int i=1;i<=sz;i++) flow_init[0][my*sz+i]=1;
    for(int i=1;i<=sz;i++) flow_init[(!my)*sz+i][sink]=1;
    for(int i=1;i<=sz;i++)
        for(int j=1;j<=sz;j++){
            if(isprime(num[my][i-1]+num[!my][j-1])) flow_init[my*sz+i][(!my)*sz+j]=1;
        }
}
void setting(){
    for(int i=0;i<=sink;i++) copy(flow_init[i],flow_init[i]+sink+1,flow[i]);
    memset(vis,0,sizeof(vis));
}
void pro(){
    int a=0;
    while(dfs(0)){
        ++a;
        for(int now=sink;now;now=bef[now]){
            --flow[bef[now]][now];
            ++flow[now][bef[now]];
        }
        memset(vis,0,sizeof(vis));
    }
    if(a==sz-1) cand.push_back(num[!my][exc-1]);
}
int main(){
    input();
    setting_initial();
    for(exc=1;exc<=sz;exc++){
        if(!isprime(num[my][0]+num[!my][exc-1])) continue;
        setting();
        pro();
    }
    sort(cand.begin(),cand.end());
    if(cand.size()){
        for(int u : cand) printf("%d ",u);
    } else return 0*puts("-1");
}
