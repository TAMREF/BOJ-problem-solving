#include <bits/stdc++.h>
using namespace std;
const int mx=1e6+5;
vector<int> G[mx];
int N, D[mx], E[mx];
void input(){
    scanf("%d",&N);
    for(int i=1,a,b;i<N;i++){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
}
void dfs(int x,int p){
    for(int u : G[x]){
        if(u!=p){
            dfs(u,x);
            D[x]+=min(D[u],E[u]);
            E[x]+=D[u];
        }
    }
    ++D[x];
}
int main(){
    input();
    dfs(1,0);
    return !printf("%d\n",min(D[1],E[1]));
}