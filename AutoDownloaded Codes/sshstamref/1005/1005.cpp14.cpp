#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int W, N,M, x, y, tc, D[1003],dt[1003];
bool col[1003];
vector<int> parent[1003], child[1003];
int getdt(int s){
    if(parent[s].empty()) return dt[s]=D[s];
    int mx=0;
    for(int &r : parent[s]) mx=max(mx, (dt[r])?(dt[r]):(getdt(r)));
    return dt[s]=mx+D[s];
}
int main(){
    scanf("%d",&tc);
    for(int m=0;m<tc;m++){
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++) scanf("%d",&D[i]);
    for(int i=0;i<M;i++){
        scanf("%d %d",&x, &y);
        child[x].push_back(y);
        parent[y].push_back(x);
    }
    scanf("%d",&W);
    printf("%d\n",getdt(W));
    for(int i=1;i<=N;i++){
        parent[i].clear();
        child[i].clear();
        dt[i]=col[i]=0;
    }
    }
}