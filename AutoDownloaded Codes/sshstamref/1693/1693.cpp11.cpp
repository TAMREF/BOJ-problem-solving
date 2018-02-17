#include <bits/stdc++.h>
using namespace std;
const int MAXC=18;
int N;
vector<int> link[100005], child[100005];
bool vis[100005];
long long memo[100005][1+MAXC];
void initial_dfs(int root){
    vis[root]=true;
    for(int &l : link[root]){
        if(vis[l]) continue;
        child[root].push_back(l);
        initial_dfs(l);
    }
}
void dfs(int root){
    for(int c=1;c<=MAXC;c++) memo[root][c]=c;
    for(int &l : child[root]){
        dfs(l);
        for(int c=1;c<=MAXC;c++){
            long long g=LLONG_MAX;
            for(int d=1;d<=MAXC;d++) if(c!=d) g=min(g,memo[l][d]);
            memo[root][c]+=g;
        }
    }
}
int main(){
    int a, b;
    scanf("%d",&N);
    for(int i=1;i<N;i++){
        scanf("%d%d",&a,&b);
        link[a].push_back(b);
        link[b].push_back(a);
    }
    initial_dfs(1); dfs(1);
    long long res=LLONG_MAX;
    for(int c=1;c<=MAXC;c++){
        res=min(res,memo[1][c]);
    }
    printf("%lld\n",res);
    return 0;
}
