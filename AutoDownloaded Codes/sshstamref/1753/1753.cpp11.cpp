#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXV = 20003, MAXE = 300005, INF = 3e6;
int V, E, K, i, j, k, x, y, z, now;
pii buk;
vector<pii> adj[MAXV];
priority_queue<pii> tam;
vector<int> ans={0};
void input(){
    scanf("%d%d%d",&V,&E,&K);
    for(i=1;i<=E;i++){
        scanf("%d%d%d",&x,&y,&z);
        adj[x].push_back(make_pair(y,z));
    }
    for(i=1;i<=V;i++){
        if(i!=K){
        tam.push(make_pair(-INF,i));
        }
        ans.push_back(INF);
    }
    tam.push(make_pair(0,K)); ans[K]=0;
}

void dijk(){
    while(!tam.empty()){
        buk = tam.top();
        tam.pop();
        if(-buk.first<=ans[buk.second]){
            for(pii &p : adj[buk.second]){
                if(p.second+ans[buk.second]<ans[p.first]){
                    ans[p.first] = p.second + ans[buk.second];
                    tam.push(make_pair(-ans[p.first],p.first));
                }
            }
        }
    }
}
void output(){
    for(i=1;i<=V;i++){
        (ans[i]!=INF)?printf("%d\n",ans[i]):puts("INF");
    }
}
int main(){
    //freopen("input.txt","rt",stdin);
    input();
    dijk();
    output();
    return 0;
}
